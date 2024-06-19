#!/usr/bin/env python3
from AI import connect
from AI import search
import sys

items_of_interest_by_level = {
    1: {"food": 7, "linemate": 1},
    2: {"food": 7, "linemate": 1, "deraumere": 1, "sibur": 1},
    3: {"food": 7, "linemate": 2, "phiras": 2, "sibur": 1},
}

def get_items_of_interest(player):
    if player.level >= 4:
        return ["Food"]
    inventory = connect.inventory(player.client)
    items = compare_items_with_dict(inventory, player.level)
    return items

def is_multiple_player_needed(player_level):
    if player_level > 1:
        return True
    else:
        return False
    
def compare_items_with_dict(inventory, level):
    missing_items = []
    items_dict = items_of_interest_by_level[level]
    for item_name, required_quantity in items_dict.items():
        found_quantity = 0
        for item in inventory:
            try:
                item = item.strip("[]\n ")
                item_name_inventory, item_value_str = item.split(maxsplit=1)
                if item_name == item_name_inventory:
                    item_value = int(item_value_str)
                    found_quantity += item_value
            except ValueError:
                missing_items = ["food"]
        
        if found_quantity < required_quantity:
            missing_items.append(item_name)
    return missing_items

def incantate(player):
    search.return_to_start(player)
    items = items_of_interest_by_level[player.level]
    for item, quantity in items.items():
        if item == "food":
            continue
        for _ in range(quantity):
            connect.drop(player.client, item)
    connect.elevate(player.client)
