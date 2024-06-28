/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Communication
*/

#include "Communication.hpp"
#include "GUI.hpp"

const std::map<std::string, GUIClient::Communication::Commands> GUIClient::Communication::_commands = {
    {"msz", Commands::MSZ},
    {"bct", Commands::BCT},
    {"tna", Commands::TNA},
    {"pnw", Commands::PNW},
    {"ppo", Commands::PPO},
    {"plv", Commands::PLV},
    {"pin", Commands::PIN},
    {"pex", Commands::PEX},
    {"pbc", Commands::PBC},
    {"pic", Commands::PIC},
    {"pie", Commands::PIE},
    {"pfk", Commands::PFK},
    {"pdr", Commands::PDR},
    {"pgt", Commands::PGT},
    {"pdi", Commands::PDI},
    {"enw", Commands::ENW},
    {"ebo", Commands::EBO},
    {"edi", Commands::EDI},
    {"sgt", Commands::SGT},
    {"sst", Commands::SST},
    {"seg", Commands::SEG},
    {"smg", Commands::SMG},
    {"suc", Commands::SUC},
    {"sbp", Commands::SBP},
    {"eht", Commands::EHT}
};

GUIClient::Communication::Communication()
{
    this->_addr.sin_family = AF_INET;

}

void GUIClient::Communication::setHost(const char *host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host);
    this->_host = host;
}

void GUIClient::Communication::setHost(std::string &host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host.c_str());
    this->_host = host;
}

void GUIClient::Communication::setPort(u_short port)
{
    this->_addr.sin_port = htons(port);
    this->_port = port;
}

void GUIClient::Communication::setPortFromString(const char *port)
{
    this->_port = (u_short) std::strtol(port, nullptr, 10);
    this->_addr.sin_port = htons(this->_port);
}

void GUIClient::Communication::setPortFromString(std::string &port)
{
    this->_port = (u_short) std::strtol(port.c_str(), nullptr, 10);
    this->_addr.sin_port = htons(this->_port);
}

/// @brief Connect to the server using the host and port set in the Communication class.
/// @return The status of the connection.
int GUIClient::Communication::connectToServer()
{
    char buffer[1024] = {0};
    int result;

    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    // fcntl(this->_socket, F_SETFL, O_NONBLOCK);
    std::cout << "Connecting to server... [" << this->_host << ":" << this->_port << "]" << std::endl;
    result = connect(this->_socket, (struct sockaddr *)&this->_addr, sizeof(this->_addr));

    if (result != 0) {
        std::cerr << "Couldn't connect to server!" << std::endl;
        return -1;
    }

    std::cout << "Waiting for server response..." << std::endl;
    if (read(this->_socket, &buffer, 1023) < 0 || strcmp(buffer, "WELCOME\n") != 0)
        return -1;
    this->_sendData("GRAPHIC\n");
    std::cout << "Connected to server!" << std::endl;
    return 0;
}

std::string GUIClient::Communication::attemptRead()
{
    fd_set readfds;
    timeval timeout = {0, 0};

    FD_SET(this->_socket, &readfds);
    int selectResult = select(this->_socket + 1, &readfds, nullptr, nullptr, &timeout);

    if (selectResult == -1) {
        std::cerr << "Error in select()" << std::endl;
        return "";
    }

    if (!FD_ISSET(this->_socket, &readfds))
        return "";

    bzero(this->_buffer, BUFFER_SIZE);
    read(this->_socket, &this->_buffer, BUFFER_SIZE - 1);

    return this->_buffer;
}

std::vector<int> GUIClient::Communication::_convertPlayerIDs(const std::vector<std::string> &playerIDs)
{
    std::vector<int> convertedIDs;

    for (std::string id : playerIDs) {
        convertedIDs.push_back(getNumber(id));
    }
    return convertedIDs;
}

std::vector<std::string> GUIClient::Communication::_splitData(std::string args) const
{
    return splitString(args, ' ');
}

void GUIClient::Communication::_sendData(const std::string &data) const
{
    write(this->_socket, data.c_str(), data.size());
}

std::string GUIClient::Communication::_requestData(const std::string &request) const
{
    char buffer[1024] = {0};
    ssize_t bytesRead;

    write(this->_socket, (void *)request.c_str(), request.size());
    bytesRead = read(this->_socket, &buffer, 1024);
    if (bytesRead == -1)
        return nullptr;
    return std::string(buffer);
}

sf::Vector2i GUIClient::Communication::_getMapSizeFromCommand(const std::vector<std::string> &command)
{
    sf::Vector2i mapSize;

    mapSize.x = getNumber(command[0]);
    mapSize.y = getNumber(command[1]);
    return mapSize;
}

GUIClient::TileComponent GUIClient::Communication::_getTileContentFromCommand(const std::vector<std::string> &command)
{
    uint8_t x = getNumber(command[0]);
    uint8_t y = getNumber(command[1]);
    GUIClient::TileComponent component(x, y);

    component.setContent({
        getNumber(command[2]),
        getNumber(command[3]),
        getNumber(command[4]),
        getNumber(command[5]),
        getNumber(command[6]),
        getNumber(command[7]),
        getNumber(command[8])
    });
    return component;
}

GUIClient::Player GUIClient::Communication::_getNewPlayerFromCommand(const std::vector<std::string> &command)
{
    Player player(getNumber(command[0]));
    std::vector<std::shared_ptr<Team>> teams = GUI::getTeams();

    player.setPos({getNumber(command[1]), getNumber(command[2]), (Orientation) getNumber(command[3])});
    player.setLevel(getNumber(command[4]));
    for (std::shared_ptr<Team> team : teams) {
        if (team->getName() == command[5]) {
            player.setTeam(team);
            break;
        }
    }
    return player;
}

GUIClient::Player::Position GUIClient::Communication::_getPlayerPositionFromCommand(const std::vector<std::string> &command)
{
    GUIClient::Player::Position pos;
    int orientation = getNumber(command[3]);

    pos.x = getNumber(command[1]);
    pos.y = getNumber(command[2]);
    switch (orientation) {
        case 1:
            pos.orientation = Orientation::UP;
            break;
        case 2:
            pos.orientation = Orientation::LEFT;
            break;
        case 3:
            pos.orientation = Orientation::DOWN;
            break;
        case 4:
            pos.orientation = Orientation::RIGHT;
            break;
        default:
            pos.orientation = Orientation::UP;
            break;
    }
    return pos;
}

GUIClient::Ressources GUIClient::Communication::_getPlayerInventoryFromCommand(const std::vector<std::string> &command)
{
    Ressources inventory;

    inventory.food = getNumber(command[3]);
    inventory.linemate = getNumber(command[4]);
    inventory.deraumere = getNumber(command[5]);
    inventory.sibur = getNumber(command[6]);
    inventory.mendiane = getNumber(command[7]);
    inventory.phiras = getNumber(command[8]);
    inventory.thystame = getNumber(command[9]);
    return inventory;
}

GUIClient::IncantationComponent GUIClient::Communication::_getIncantationFromCommand(const std::vector<std::string> &command)
{
    IncantationComponent incantation(
        getNumber(command[0]),
        getNumber(command[1]),
        getNumber(command[2])
    );

    return incantation;
}

void GUIClient::Communication::_handleRessourceDrop(const std::vector<std::string> &command, GUI &gui)
{
    Player &player = gui.getPlayer(getNumber(command[0]));
    RessourceID ressourceId = (RessourceID) getNumber(command[1]);

    gui.getMap().getTile(player.getX(), player.getY()).getContent().addRessource(ressourceId);
    player.getInventory().getContent().removeRessource(ressourceId);
}

void GUIClient::Communication::_handleRessourceCollection(const std::vector<std::string> &command, GUI &gui)
{
    Player &player = gui.getPlayer(getNumber(command[0]));
    RessourceID ressourceId = (RessourceID) getNumber(command[1]);

    gui.getMap().getTile(player.getX(), player.getY()).getContent().removeRessource(ressourceId);
    player.getInventory().getContent().addRessource(ressourceId);
}

sf::Vector2i GUIClient::Communication::requestMapSize()
{
    std::vector<std::string> data;
    sf::Vector2i mapSize;

    data = this->_splitData(this->_requestData("msz\n"));

    mapSize.x = getNumber(data[1]);
    mapSize.y = getNumber(data[2]);
    return mapSize;
}

int GUIClient::Communication::requestPlayerLevel(int playerId)
{
    std::vector<std::string> data;
    std::string request = "plv #" + std::to_string(playerId) + "\n";
    int level;

    data = this->_splitData(this->_requestData(request));
    level = getNumber(data[2]);
    return level;
}

GUIClient::Ressources GUIClient::Communication::requestTileContent(int x, int y)
{
    std::vector<std::string> data;
    std::string request = "bct " + std::to_string(x) + " " + std::to_string(y) + "\n";
    Ressources content;

    data = this->_splitData(this->_requestData(request));
    content.food = getNumber(data[4]);
    content.linemate = getNumber(data[5]);
    content.deraumere = getNumber(data[6]);
    content.sibur = getNumber(data[7]);
    content.mendiane = getNumber(data[8]);
    content.phiras = getNumber(data[9]);
    content.thystame = getNumber(data[10]);
    return content;
}

GUIClient::Ressources GUIClient::Communication::requestPlayerInventory(int playerId)
{
    std::vector<std::string> data;
    std::string request = "pin #" + std::to_string(playerId) + "\n";
    Ressources inventory;

    data = this->_splitData(this->_requestData(request));
    inventory.food = getNumber(data[4]);
    inventory.linemate = getNumber(data[5]);
    inventory.deraumere = getNumber(data[6]);
    inventory.sibur = getNumber(data[7]);
    inventory.mendiane = getNumber(data[8]);
    inventory.phiras = getNumber(data[9]);
    inventory.thystame = getNumber(data[10]);
    return inventory;
}

void GUIClient::Communication::runCommand(Commands command, std::vector<std::string> &args, GUI &gui)
{
    switch (command) {
        case Commands::MSZ:
            gui.getMap().create(this->_getMapSizeFromCommand(args));
            break;
        case Commands::BCT:
            gui.getMap().setTile(this->_getTileContentFromCommand(args));
            break;
        case Commands::TNA:
            gui.addTeam(args[0]);
            break;
        case Commands::PNW:
            gui.addPlayer(this->_getNewPlayerFromCommand(args));
            break;
        case Commands::PPO:
            gui.getPlayer(getNumber(args[0])).setPos(this->_getPlayerPositionFromCommand(args));
            break;
        case Commands::PLV:
            gui.getPlayer(getNumber(args[0])).setLevel(getNumber(args[1]));
            break;
        case Commands::PIN:
            gui.getPlayer(getNumber(args[0])).getInventory().setContent(this->_getPlayerInventoryFromCommand(args));
            break;
        case Commands::PEX:
            gui.removePlayer(getNumber(args[0]));
            break;
        case Commands::PBC:
            break;
        case Commands::PIC:
            gui.startIncantation(this->_getIncantationFromCommand(args), this->_convertPlayerIDs(args + 3));
            break;
        case Commands::PIE:
            gui.stopIncantation(this->_getIncantationFromCommand(args));
            break;
        case Commands::PFK:
            break;
        case Commands::PDR:
            this->_handleRessourceDrop(args, gui);
            break;
        case Commands::PGT:
            this->_handleRessourceCollection(args, gui);
            break;
        case Commands::PDI:
            gui.removePlayer(getNumber(args[0]));
            break;
        case Commands::ENW:
            break;
        case Commands::EBO:
            break;
        case Commands::EDI:
            break;
        case Commands::SGT:
            break;
        case Commands::SST:
            break;
        case Commands::SEG:
            break;
        case Commands::SMG:
            gui.writeServerMessage(args[0]);
            break;
        case Commands::SUC:
            break;
        case Commands::SBP:
            break;
        case Commands::EHT:
            break;
        default: break;
    }
}

void GUIClient::Communication::handleCommunications(GUI &gui)
{
    std::string rawCommands = this->attemptRead();
    if (rawCommands == "")
        return;
    std::vector<std::string> commands = splitString(rawCommands, '\n', true);
    commands.pop_back();

    for (std::string &command : commands) {
        command.pop_back();
        std::cout << "Command: " << command << std::endl;
        std::vector<std::string> commandArgs = splitString(command, ' ');
        std::string commandName = commandArgs[0];
        commandArgs.erase(commandArgs.begin());
        if (this->_commands.contains(commandName))
            this->runCommand(this->_commands.at(commandName), commandArgs, gui);
        else
            std::cerr << "Unknown command: " << commandName << std::endl;
    }
}
