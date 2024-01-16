#include <iostream>

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				return true;
			}
		}
	}return false;
}

int evaluate(char board[3][3]) 
{
	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
		{
			if (board[row][0] == player)
			{
				return +10;
			}
			else if (board[row][0] == opponent)
			{
				return -10;
			}
		}
	}
	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
		{
			if (board[0][col] == player)
			{
				return +10;
			}
			else if (board[0][col] == opponent)
			{
				return -10;
			}
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == player)
		{
			return +10;
		}
		else if (board[0][0] == opponent)
		{
			return -10;
		}
	}if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == player)
		{
			return +10;
		}
		else if (board[0][2] == opponent)
		{
			return -10;
		}
	}
	return 0;
}

void printBoard(char board[3][3]) 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int miniMax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);
	if (score == 10)
	{
		return score;
	}

	if (score == -10)
	{
		return score;
	}
	if (isMovesLeft(board) == false)
	{
		return 0;
	}

	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = player;

					//printBoard(board);

					best = std::max(best, miniMax(board, depth + 1, !isMax));

					board[i][j] = '_';
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = opponent;

					//printBoard(board);

					best = std::min(best, miniMax(board, depth + 1, !isMax));
								
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.col = -1;
	bestMove.row = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				board[i][j] = player;

				printBoard(board);

				int moveVal = miniMax(board, 0, false);

				board[i][j] = '_';

				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	printf("The best move value is: %d\n\n", bestVal);
	return bestMove;
}


void main() {
	std::cout << "tictactoe" << std::endl;
	
	char board[3][3] = 
	{
	{ 'x', 'o', 'x'},
	{ '_', '_', '_'},
	{ 'o', '_', '_'}
	};
	//printBoard(board);
	Move bestMove = findBestMove(board);
	printf("The Optimal Move is :\n");
	printf("ROW: %d COL: %d\n\n", bestMove.row,
		bestMove.col);
}