# Naming convention:
## Branches:
When creating a new branch follow this template to name it:  
`<Your trigram>/<task on the branch>`  
Example: John Smith want to create a branch to update the readme.  
He could create a branch: `jst/update-readme`  
Please always keep the same trigram for this project.  

## Commits:
When committing on your branch use this template:  
`[<Type of modification>]: <Modification's target part>: <Details>`  

List of possible types of modification:  
- `WIP`: Work in progress
- `ADD`: add a file/a feature/anything new
- `RM`: remove a file/a directory
- `FIX`: fix something on a file

Full commits examples:  
- `[FIX]: map display: full display of the the map`
- `[ADD]: server routes: route to register a new player`
- `[RM]: test file pushed by mistake`
- `[WIP]: map display: wip`

# Task/Issue process:
Everything begin with an issue:  
- Create an issue with the team or with your mate.
- **Assign** the issue to yourself or your mate
- **Label** it (ADD, FIX, DOC, RM)
- Set as **project** the Zappy github project
- Select the relative **milestone** (SERVER, GUI, IA, PROJECT MANAGEMENT)
- Select in **development** the branch solving your issue

Create your branch and do your work..
Each of your pushs will trigger the relative pipeline check on github, fix your code looking to the logs of the pipeline if it fails.

When you think that your issue is resolved, and **before review**, you will have:
- **Pushed** your modifications and the relative **unit tests** for your code on **your branch**
- **Created** and filled with details about your issue, a **pull request**
- **Assigned** your mate to review your code and tag him/her in the **ask-reviews** discord server conversation

Then your mate will review your PR to approve it.
You or your mate will then merge your PR to the `dev` branch.
