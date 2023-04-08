#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}
   
TEST_CASE("Test game over if 9 slots are selected")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(6);
	game.mark_board(4);
	game.mark_board(7);
	game.mark_board(9);
	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	
}

TEST_CASE("Test win by first columm")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win by second column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(5);
	game.mark_board(7);
	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win by third column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win by first row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(7);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win by second row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	game.mark_board(3);
	game.mark_board(5);
	game.mark_board(7);
	game.mark_board(6);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win by third row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(8);
	game.mark_board(5);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win diagonally from top left")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test win diagonally from bottom left")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(8);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE((game.get_winner() == "X" || game.get_winner() == "O"));
}

TEST_CASE("Test TicTacToeManager get_winner_total function")
{
	int o = 0, w = 0, t = 0;
	
	TicTacToe game1;
	TicTacToeManager manager;
	game1.start_game("X");
	game1.mark_board(3);
	game1.mark_board(4);
	game1.mark_board(6);
	game1.mark_board(7);
	game1.mark_board(9);
	if(game1.game_over())
	{
		manager.save_game(game1);
	}
	

	TicTacToe game2;
	game2.start_game("O");
	game2.mark_board(3);
	game2.mark_board(4);
	game2.mark_board(6);
	game2.mark_board(7);
	game2.mark_board(9);
	if(game2.game_over())
	{
		manager.save_game(game2);
	}
	
	

	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(1);
	game3.mark_board(2);
	game3.mark_board(5);
	game3.mark_board(3);
	game3.mark_board(6);
	game3.mark_board(4);
	game3.mark_board(7);
	game3.mark_board(9);
	game3.mark_board(8);
	if(game3.game_over())
	{
		manager.save_game(game3);
	}
	
	
	manager.get_winner_total(o,w,t);
	REQUIRE(t == 1);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	
}


