# CMakeList.txt : CMake project for DeadMansDraw, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DeadMansDraw "main.cpp" "main.h" "gameTitle.h" "Game.cpp" "Game.h" "Deck.h" "Deck.cpp" "Cards/Card.h" "Player.h" "PlayArea.h" "Bank.h" "Cards/Cannon.cpp" "Cards/Cannon.h" "Cards/Suit.h" "Cards/Chest.cpp" "Cards/Key.h" "Cards/Key.cpp" "Cards/Sword.h" "Cards/Sword.cpp" "Cards/Hook.h" "Cards/Hook.cpp" "Cards/Oracle.cpp" "Cards/Map.cpp" "Cards/Mermaid.cpp" "Cards/Kraken.cpp" "Cards/Oracle.h" "Cards/Map.h" "Cards/Mermaid.h" "Cards/Kraken.h" "Player.cpp" "PlayArea.cpp" "CardCollection.h" "Bank.cpp" "Discard.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DeadMansDraw PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
