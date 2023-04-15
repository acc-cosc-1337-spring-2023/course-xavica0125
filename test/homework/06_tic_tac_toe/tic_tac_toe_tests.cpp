#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
int o = 0, w = 0, t = 0;
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}
   
TEST_CASE("Test game over if 9 slots are selected")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);
	game->mark_board(4);
	game->mark_board(7);
	game->mark_board(9);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	
}

TEST_CASE("Test win by first columm")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by second column")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(3);
	game->mark_board(5);
	game->mark_board(7);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by third column")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(4);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by first row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by second row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(3);
	game->mark_board(5);
	game->mark_board(7);
	game->mark_board(6);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by third row")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(8);
	game->mark_board(5);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win diagonally from top left")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win diagonally from bottom left")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(8);
	game->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test unique_ptr<TicTacToe3>Manager get_winner_total function")
{
	unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
	TicTacToeManager manager;
	game1->start_game("X");
	game1->mark_board(3);
	game1->mark_board(4);
	game1->mark_board(6);
	game1->mark_board(7);
	game1->mark_board(9);
	if(game1->game_over())
	{
		manager.save_game(game1);
	}
	

	unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
	game2->start_game("O");
	game2->mark_board(3);
	game2->mark_board(4);
	game2->mark_board(6);
	game2->mark_board(7);
	game2->mark_board(9);
	if(game2->game_over())
	{
		manager.save_game(game2);
	}
	
	unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
	game3->start_game("X");
	game3->mark_board(1);
	game3->mark_board(2);
	game3->mark_board(5);
	game3->mark_board(3);
	game3->mark_board(6);
	game3->mark_board(4);
	game3->mark_board(7);
	game3->mark_board(9);
	game3->mark_board(8);
	if(game3->game_over())
	{
		manager.save_game(game3);
	}

	manager.get_winner_total(o,w,t);
	REQUIRE(t == 1);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	
}

TEST_CASE("Test first player set to X 4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}
   
TEST_CASE("Test game over if 16 slots are selected 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(3);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(11);
	game->mark_board(12);
	game->mark_board(16);
	game->mark_board(15);
	game->mark_board(14);
	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	
}

TEST_CASE("Test win by first columm 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by second column 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(6);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(8);
	game->mark_board(14);
	
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by third column 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(5);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(11);
	game->mark_board(9);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(8);
	game->mark_board(10);
	game->mark_board(12);
	game->mark_board(9);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by first row 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(9);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by second row 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(10);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by third row 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(9);
	game->mark_board(2);
	game->mark_board(10);
	game->mark_board(5);
	game->mark_board(11);
	game->mark_board(16);
	game->mark_board(12);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win by fourth row 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	game->mark_board(2);
	game->mark_board(14);
	game->mark_board(5);
	game->mark_board(15);
	game->mark_board(8);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}
TEST_CASE("Test win diagonally from top left 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(4);
	game->mark_board(6);
	game->mark_board(9);
	game->mark_board(11);
	game->mark_board(12);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}

TEST_CASE("Test win diagonally from bottom left 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	game->mark_board(2);
	game->mark_board(10);
	game->mark_board(8);
	game->mark_board(7);
	game->mark_board(11);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE((game->get_winner() == "X" || game->get_winner() == "O"));
}


TEST_CASE("Test unique_ptr<TicTacToe4>Manager get_winner_total function")
{
	unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
	TicTacToeManager manager;
	game1->start_game("X");
	game1->mark_board(16);
	game1->mark_board(2);
	game1->mark_board(11);
	game1->mark_board(8);
	game1->mark_board(6);
	game1->mark_board(13);
	game1->mark_board(1);
	if(game1->game_over())
	{
		manager.save_game(game1);
	}
	

	unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
	game2->start_game("O");
	game2->mark_board(13);
	game2->mark_board(2);
	game2->mark_board(14);
	game2->mark_board(5);
	game2->mark_board(15);
	game2->mark_board(8);
	game2->mark_board(16);
	if(game2->game_over())
	{
		manager.save_game(game2);
	}
	
	unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();
	game3->start_game("X");
	game3->mark_board(1);
	game3->mark_board(2);
	game3->mark_board(3);
	game3->mark_board(4);
	game3->mark_board(5);
	game3->mark_board(6);
	game3->mark_board(7);
	game3->mark_board(8);
	game3->mark_board(9);
	game3->mark_board(10);
	game3->mark_board(11);
	game3->mark_board(12);
	game3->mark_board(16);
	game3->mark_board(15);
	game3->mark_board(14);
	game3->mark_board(13);
	if(game3->game_over())
	{
		manager.save_game(game3);
	}
	
	manager.get_winner_total(o,w,t);
	REQUIRE(t == 1);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	
}
