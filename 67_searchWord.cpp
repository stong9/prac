bool exist(vector<vector<char> > &board, string word) {
	// Start typing your Java solution below
	// DO NOT write main() function
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[0].size(); j++){
			if(board[i][j] == word[0])
			if(helper(board, i, j, 1, word))
			return true;
		}
	}
	return false;
}
bool helper(vector<vector<char> > &board, int r, int c, int searching, string word){
	if(searching == word.size()) 
	return true;
	char ch = board[r][c];
	board[r][c] = '#';
	// Up
	if(r > 0 && board[r - 1] [c] == word[searching]){
		
		
		if(helper(board, r - 1, c, searching+1, word))
		return true;
		
	}
	// Right
	if(c < board[0].size() - 1 && board[r] [c + 1] == word[searching]){
		
		if(helper(board, r, c + 1, searching+1, word))
		return true;
		
	}
	// Down
	if(r < board.size() - 1 && board[r + 1] [c] == word[searching]){
		
		if(helper(board, r + 1, c, searching+1, word))
		return true;
		
	}
	// Left
	if(c > 0 && board[r] [c - 1] == word[searching]){
		
		if(helper(board, r, c - 1, searching+1, word))
		return true;
		
	}
	board[r][c] = ch;
	return false;
}