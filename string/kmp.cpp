void get_next(const string &s, int nxt[]) {
	nxt[0] = -1;
	int k = -1;
	
	for (int i = 1; i < s.length(); ++i) {
		while(k > -1 && s[k + 1] != s[i]) k = nxt[k];
		if (s[k + 1] == s[i]) k++;
		nxt[i] = k;
	} 
}
