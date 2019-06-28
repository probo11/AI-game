// utttbot.cpp
// Aswin van Woudenberg

#include "utttbot.h"
#include <iostream>
#include <sstream>
#include <string>
#include <list>

void UTTTBot::run() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<std::string> command = split(line, ' ');
		if (command[0] == "settings") {
			setting(command[1], command[2]);
		}
		else if (command[0] == "update" && command[1] == "game") {
			update(command[2], command[3]);
		}
		else if (command[0] == "action" && command[1] == "move") {
			move(std::stoi(command[2]));
		}
		else {
			std::cerr << "Unknown command: " << line << std::endl;
		}
	}
}

State b;
Player player;
Player opponent;

int eval(const State &board, const Player &player)
{

	Player opponent; if (player == Player::X){ opponent = Player::O; } else { opponent = Player::X; }

    // 3oprij horizontaal

    
     if(board.macroboard[0][0] == player && board.macroboard[0][1] == player && board.macroboard[0][2] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[0][1] == opponent && board.macroboard[0][2] == opponent)
    {
        return -1000000;
    }
    
    if(board.macroboard[1][0] == player && board.macroboard[1][1] == player && board.macroboard[1][2] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[1][0] == opponent && board.macroboard[1][1] == opponent && board.macroboard[1][2] == opponent)
    {
        return -1000000;
    }
    
    if(board.macroboard[2][0] == player && board.macroboard[2][1] == player && board.macroboard[2][2] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[2][0] == opponent && board.macroboard[2][1] == opponent && board.macroboard[2][2] == opponent)
    {
        return -1000000;
    }
    
    // 3oprij verticaal
    
    if(board.macroboard[0][0] == player && board.macroboard[1][0] == player && board.macroboard[2][0] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[1][0] == opponent && board.macroboard[2][0] == opponent)
    {
        return -1000000;
    }
    
    if(board.macroboard[0][1] == player && board.macroboard[1][1] == player && board.macroboard[2][1] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[0][1] == opponent && board.macroboard[1][1] == opponent && board.macroboard[2][1] == opponent)
    {
        return -1000000;
    }
    
    if(board.macroboard[0][2] == player && board.macroboard[1][2] == player && board.macroboard[2][2] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[1][2] == opponent && board.macroboard[2][2] == opponent)
    {
        return -1000000;
    }
    
    // 3oprij diagonaal
    
    if(board.macroboard[0][0] == player && board.macroboard[1][1] == player && board.macroboard[2][2] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[1][1] == opponent && board.macroboard[2][2] == opponent)
    {
        return -1000000;
    }
    
    if(board.macroboard[2][2] == player && board.macroboard[1][1] == player && board.macroboard[2][0] == player)
    {
        return 1000000;
    }
    else if(board.macroboard[2][2] == opponent && board.macroboard[1][1] == opponent && board.macroboard[2][0] == opponent)
    {
        return -1000000;
    }
    
    /*
        MACROBOARD 2 op rij
    */
    //horizontaal 2 op rij, rij 1
    if(board.macroboard[0][0] == player && board.macroboard[0][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[0][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][2] == player && board.macroboard[0][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[0][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][2] == player && board.macroboard[0][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[0][0] == opponent)
    {
        return -10000;
    }
    
    //horizontaal 2 op rij, rij 2
    
    if(board.macroboard[1][0] == player && board.macroboard[1][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][0] == opponent && board.macroboard[1][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[1][2] == player && board.macroboard[1][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][2] == opponent && board.macroboard[1][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[1][0] == player && board.macroboard[1][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][0] == opponent && board.macroboard[1][2] == opponent)
    {
        return -10000;
    }
    
    //horizontaal 2 op rij, rij 3
    if(board.macroboard[2][0] == player && board.macroboard[2][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[2][0] == opponent && board.macroboard[2][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[2][2] == player && board.macroboard[2][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[2][2] == opponent && board.macroboard[2][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[2][0] == player && board.macroboard[2][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[2][0] == opponent && board.macroboard[2][2] == opponent)
    {
        return -10000;
    }
    // verticaal 2 op rij, kolom 0
    // 0,0  0,1  0,2
    // 1,0  1,1  1,2
    // 2,0  2,1  2,2
    if(board.macroboard[0][0] == player && board.macroboard[1][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[1][0] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[1][0] == player && board.macroboard[2][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][0] == opponent && board.macroboard[2][0] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[0][0] == player && board.macroboard[2][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[2][0] == opponent)
    {
        return -10000;
    }
    // verticaal 2 op rij, kolom 1
    // 0,0  0,1  0,2
    // 1,0  1,1  1,2
    // 2,0  2,1  2,2
    if(board.macroboard[0][1] == player && board.macroboard[0][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][1] == opponent && board.macroboard[0][1] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[1][1] == player && board.macroboard[2][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][1] == opponent && board.macroboard[2][1] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][1] == player && board.macroboard[2][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][1] == opponent && board.macroboard[2][1] == opponent)
    {
        return -10000;
    }
    // verticaal 2 op rij, kolom 2
    // 0,0  0,1  0,2
    // 1,0  1,1  1,2
    // 2,0  2,1  2,2
    if(board.macroboard[0][2] == player && board.macroboard[1][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[1][2] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[1][2] == player && board.macroboard[2][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][2] == opponent && board.macroboard[2][2] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][2] == player && board.macroboard[2][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[2][2] == opponent)
    {
        return -10000;
    }
    // diagonaal van linksboven naar rechtsonder
    // 0,0  0,1  0,2
    // 1,0  1,1  1,2
    // 2,0  2,1  2,2
    if(board.macroboard[0][0] == player && board.macroboard[1][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[1][1] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[1][1] == player && board.macroboard[2][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][1] == opponent && board.macroboard[2][2] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][0] == player && board.macroboard[2][2] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][0] == opponent && board.macroboard[2][2] == opponent)
    {
        return -10000;
    }
    //diagonaal van rechtsboven naar linksonder
    // 0,0  0,1  0,2
    // 1,0  1,1  1,2
    // 2,0  2,1  2,2
    if(board.macroboard[0][2] == player && board.macroboard[1][1] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[1][1] == opponent)
    {
        return -10000;
    }
    if(board.macroboard[1][1] == player && board.macroboard[2][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[1][1] == opponent && board.macroboard[2][0] == opponent)
    {
        return -10000;
    }
    
    if(board.macroboard[0][2] == player && board.macroboard[2][0] == player)
    {
        return 10000;
    }
    else if(board.macroboard[0][2] == opponent && board.macroboard[2][0] == opponent)
    {
        return -10000;
    }
    
    /*
        MACROBOARD 1 vak
    */
    // 1 vak midden
    if(board.macroboard[1][1] == player)
    {
        return 5000;
    }
    else if(board.macroboard[1][1] == opponent)
    {
        return -5000;
    }
    // 1 vak hoeken
    if(board.macroboard[0][0] == player)
    {
        return 3000;
    }
    else if(board.macroboard[0][0] == opponent)
    {
        return -3000;
    }
    if(board.macroboard[0][2] == player)
    {
        return 3000;
    }
    else if(board.macroboard[0][2] == opponent)
    {
        return -3000;
    }
    if(board.macroboard[2][0] == player)
    {
        return 3000;
    }
    else if(board.macroboard[2][0] == opponent)
    {
        return -3000;
    }
    if(board.macroboard[2][2] == player)
    {
        return 3000;
    }
    else if(board.macroboard[2][2] == opponent)
    {
        return -3000;
    }
    
    // 1 vak randen
    if(board.macroboard[0][1] == player)
    {
        return 1500;
    }
    else if(board.macroboard[0][1] == opponent)
    {
        return -1500;
    }
    if(board.macroboard[2][1] == player)
    {
        return 1500;
    }
    else if(board.macroboard[2][1] == opponent)
    {
        return -1500;
    }
    if(board.macroboard[1][0] == player)
    {
        return 1500;
    }
    else if(board.macroboard[1][0] == opponent)
    {
        return -1500;
    }
    if(board.macroboard[1][2] == player)
    {
        return 1500;
    }
    else if(board.macroboard[1][2] == opponent)
    {
        return -1500;
    }
    
    
	return 0;
}

MoveEval alphaBeta(State &board, int ply, Player player, Player opponent, int alpha, int beta)
{
	if (ply == 0)
		return std::make_pair(Move(), eval(board, player));

	std::vector<Move> moves = getMoves(board);
	if (moves.size() == 0)
		return std::make_pair(Move(), eval(board, player));

	MoveEval best = std::make_pair(Move(), alpha);
	for (Move &move : moves) {
		State s = doMove(board, move);
		MoveEval me;
		if(moves.size() > 9 && ply > 2)
		{
		    me = alphaBeta(s, ply - 2, opponent, player, -beta, -alpha);
		}else{ me = alphaBeta(s, ply - 1, opponent, player, -beta, -alpha);}

		if (-me.second > alpha) {
			alpha = -me.second;
			best = std::make_pair(move, alpha);
		}
		if (alpha >= beta)
			return best;
	}
	return best;
}

Move alphaBeta(const State &board, int ply)
{
	State b = board;
	Player player = getCurrentPlayer(b);
	Player opponent;
	if (player == Player::O) { opponent = Player::X; }
	else { opponent = Player::O; }

    b = board;
    player = player;
    opponent = opponent;
    
	return alphaBeta(b, ply, player, opponent, std::numeric_limits<int>::min() + 1, std::numeric_limits<int>::max()).first;
}

void UTTTBot::move(int timeout) {
    std::cout << "place_disc " << alphaBeta(state, 5) << std::endl;
  
}



void UTTTBot::update(std::string &key, std::string &value) {
	if (key == "round") {
		round = std::stoi(value);
	}
	else if (key == "field") {
		int row = 0;
		int col = 0;
		std::vector<std::string> fields = split(value, ',');
		for (std::string &field : fields) {
			if (field == "0") {
				state.board[row][col] = Player::X;
			}
			else if (field == "1") {
				state.board[row][col] = Player::O;
			}
			else {
				state.board[row][col] = Player::None;
			}
			col++;
			if (col == 9) {
				row++;
				col = 0;
			}
		}
	}
	else if (key == "macroboard") {
		int row = 0;
		int col = 0;
		std::vector<std::string> fields = split(value, ',');
		for (std::string &field : fields) {
			if (field == "-1") {
				state.macroboard[row][col] = Player::Active;
			}
			else if (field == "0") {
				state.macroboard[row][col] = Player::X;
			}
			else if (field == "1") {
				state.macroboard[row][col] = Player::O;
			}
			else {
				state.macroboard[row][col] = Player::None;
			}
			col++;
			if (col == 3) {
				row++;
				col = 0;
			}
		}
	}
}

void UTTTBot::setting(std::string &key, std::string &value) {
	if (key == "timebank") {
		timebank = std::stoi(value);
	}
	else if (key == "time_per_move") {
		time_per_move = std::stoi(value);
	}
	else if (key == "player_names") {
		std::vector<std::string> names = split(value, ',');
		player_names[0] = names[0];
		player_names[1] = names[1];
	}
	else if (key == "your_bot") {
		your_bot = value;
	}
	else if (key == "your_botid") {
		your_botid = std::stoi(value);
	}
}

std::vector<std::string> UTTTBot::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

