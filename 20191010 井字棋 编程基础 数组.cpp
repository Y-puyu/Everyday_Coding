// 暴力列举法
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		// 利用纵、横、斜相加数值和为3，即3子连珠玩家获胜
		if ((board[0][0] + board[1][1] + board[2][2]) == 3 ||     // 主斜对角线
			(board[0][2] + board[1][1] + board[2][0]) == 3 ||     // 副斜对角线
			(board[0][0] + board[0][1] + board[0][2]) == 3 ||     // 第一列
			(board[0][0] + board[0][1] + board[0][2]) == 3 ||     // 第二列
			(board[1][0] + board[1][1] + board[1][2]) == 3 ||     // 第三列
			(board[0][0] + board[0][1] + board[0][2]) == 3 ||     // 第一行
			(board[1][0] + board[1][1] + board[1][2]) == 3 ||     // 第二行
			(board[2][0] + board[2][1] + board[2][2]) == 3)       // 第三行
			return true;
		return false;
	}
};

// 一般方法
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int row = board.size();
		// 检查每一行的和是否等于row
		int i, j, sum;
		for (i = 0; i < row; ++i) {
			sum = 0;
			for (j = 0; j < row; ++j) {
				sum += board[i][j];
			}

			if (sum == row)
				return true;
		}

		// 检查每一列的和是否等于row
		sum = 0;
		for (i = 0; i < row; ++i) {
			sum = 0;
			for (j = 0; j < row; ++j) {
				sum += board[j][i];
			}

			if (sum == row)
				return true;
		}

		//检查主对角线的和是否等于row
		sum = 0;
		for (i = 0; i < row; ++i) {
			sum += board[i][i];
		}

		if (sum == row)
			return true;

		// 检查副对角线的和是否等于row
		sum = 0;
		for (i = 0; i < row; ++i) {
			sum += board[i][row - 1 - i];
		}

		if (sum == row)
			return true;
		return false;
	}
};