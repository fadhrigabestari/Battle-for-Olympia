# Battle-for-Olympia
A game inspired by Battle for Wesnoth that i created for a school project in C language.

READ ME :
1. Download all the necessary files
  1.1. ADT Driver consists of all the necesarry files to run the game. The driver is created for preliminary tests so i can be sure
    that all the files required are working as intended.
  1.2. Source Code consists of all the necesarry files to run the game (also). You can create the executable file of the game from this
    folder. Use command line, "gcc matriks.c listVILLAGE.c listPLAYER.c listUNIT.c pcolor.c point.c recruitcommand.c changeunit.c InitializeNew.c 
      move.c queuePLAYER.c attack.c stackt.c mesinkata.c mesinkar.c BattleForOlympia.c -o BfO" to create BfO.exe. I recommend using
        Windows PowerShell.
  1.3. Battle for Olympia consists of the executable file I created. If you just want to play the game, just run the game using
    Windows PowerShell with command line, "./BattleforOlympia"
    
2. Play the game!
  This game is designed to be played with 2 players, with each side having one King to start off with. The goal of the game is simple, kill the other player's King! You can reqruit additional units to help you gain the upper hand. Be mindful of each unit's cost and upkeep, and how you balance your gold spendings with income from available villages scattered around the map.
  Inside the game, input these commands to :
    MAP.		-- Show the current map.
    MOVE.		-- Move your currently selected unit to a desired location.
    UNDO.		-- Return your currently selected unit to it's previous location. "UNDO." command will not be available if input other than                    "MOVE.", "UNDO.", "MAP.", and "INFO." is used.
    RECRUIT.	-- Recruit a Swordsman, an Archer, or a WhiteMage into the game. To recruit an additional unit, you need to have at least one                  unoccupied castle. Recruitted unit has to be spawned in one of those unoccupied castle.
    CHANGE_UNIT.	-- Change currently selected to a another unit.
    NEXT_UNIT.	-- Change currently selected to the next available unit.
    INFO.		-- Show the current status of your unit and its surroundings.
    ATTACK.		-- Attack an enemy unit next to your currently selected unit. A unit with different attack type won't be able to retaliate.
    END_TURN.	-- End your turn.
    EXIT.		-- Exit the game.
