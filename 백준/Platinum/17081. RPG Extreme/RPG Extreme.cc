#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define inf 1987654321
using namespace std;
class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
debugstream dout(cout);
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef struct {
	int r, c;
} pos;
typedef struct {
	char type;
	int atk;
	int def;
	string acc_type;
} box;
typedef struct {
	pos cur_pos;
	int level, max_hp, hp, att, def, exp;
	bool hr, re, co, ex, dx, hu, cu;
	int add_att, add_def;
	int acc_cnt;
} character;
typedef struct {
	pos cur_pos;
	string name;
	int att, def, hp, exp;
} monster;
typedef struct {
	pos cur_pos;
	string name;
	int att, def, hp, exp;
} boss_monster;
bool operator< (const pos& p1, const pos& p2) {
	if (p1.r == p2.r) return p1.c < p2.c;
	return p1.r < p2.r;
}
bool operator== (const pos& p1, const pos& p2) {
	return p1.r == p2.r && p1.c == p2.c;
}
ostream& operator<<(ostream& os, const pos& p) {
	return os << '(' << p.r << ' ' << p.c << ')';
}
ostream& operator<<(ostream& os, const character& c) {
	os << "LV : " << c.level << endl;
	os << "HP : " << c.hp << '/' << c.max_hp << endl;
	os << "ATT : " << c.att << '+' << c.add_att << endl;
	os << "DEF : " << c.def << '+' << c.add_def << endl;
	os << "EXP : " << c.exp << '/' << c.level * 5;
	return os;
}
int main() {
	FASTIO;
	int n, m; cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	character hero = { -1, -1, 1, 20, 20, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	map<pos, box> boxes;
	map<pos, monster> monsters;
	boss_monster boss;
	string cmds;
	pos start;

	for (int i = 0; i < n; i++) {
		cin.ignore();
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '@') {
				start = { i, j };
				hero.cur_pos = { i, j };
				board[i][j] = '.';
			}
			if (board[i][j] == '&') monsters[{ i, j }] = monster();
			if (board[i][j] == 'M') boss.cur_pos = { i, j };
			if (board[i][j] == 'B') boxes[{ i, j }] = box();
		}
	}

	cin >> cmds;

	for (int i = 0; i < monsters.size() + 1; i++) {
		int r, c; string name;
		int w, a, h, e;
		cin >> r >> c >> name >> w >> a >> h >> e;
		r--, c--;
		if (r == boss.cur_pos.r && c == boss.cur_pos.c) {
			boss = { r, c, name, w, a, h, e };
		}
		else {
			monsters[{r, c}] = { r, c, name, w, a, h, e };
		}
	}
	for (int i = 0; i < boxes.size(); i++) {
		int r, c; char t;
		cin >> r >> c; cin.ignore(); cin >> t;
		r--, c--;
		if (t == 'W') {
			boxes[{ r, c }].type = 'W';
			cin >> boxes[{ r, c }].atk;
		}
		if (t == 'A') {
			boxes[{ r, c }].type = 'A';
			cin >> boxes[{ r, c }].def;
		}
		if (t == 'O') {
			boxes[{ r, c }].type = 'O';
			cin >> boxes[{ r, c }].acc_type;
		}
	}

	int t = 0;
	while (t < cmds.size()) {
		if (cmds[t] == 'L') {
			if (hero.cur_pos.c > 0 && board[hero.cur_pos.r][hero.cur_pos.c - 1] != '#')
				hero.cur_pos.c--;
		}
		else if (cmds[t] == 'R') {
			if (hero.cur_pos.c < m - 1 && board[hero.cur_pos.r][hero.cur_pos.c + 1] != '#')
				hero.cur_pos.c++;
		}
		else if (cmds[t] == 'U') {
			if (hero.cur_pos.r > 0 && board[hero.cur_pos.r - 1][hero.cur_pos.c] != '#')
				hero.cur_pos.r--;
		}
		else if (cmds[t] == 'D') {
			if (hero.cur_pos.r < n - 1 && board[hero.cur_pos.r + 1][hero.cur_pos.c] != '#')
				hero.cur_pos.r++;
		}

		if (board[hero.cur_pos.r][hero.cur_pos.c] == '^') {
			if (hero.dx) hero.hp -= 1;
			else hero.hp -= 5;
			if (hero.hp <= 0) {
				if (hero.re) {
					hero.hp = hero.max_hp;
					hero.cur_pos = start;
					hero.re = 0;
					hero.acc_cnt--;
				}
				else {
					hero.hp = 0;
					vector<vector<char>> temp(n, vector<char>(m));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
					}
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) cout << temp[i][j];
						cout << endl;
					}
					cout << "Passed Turns : " << ++t << endl;
					cout << hero << endl;
					cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
					return 0;
				}
			}
		}
		else if (board[hero.cur_pos.r][hero.cur_pos.c] == '&') {
			monster enermy = monsters[hero.cur_pos];
			int hero_att = hero.att + hero.add_att;
			int hero_def = hero.def + hero.add_def;
			if (hero.co) {
				if (hero.dx) enermy.hp -= max<int>(1, hero_att * 3 - enermy.def);
				else enermy.hp -= max<int>(1, hero_att * 2 - enermy.def);
			}
			else enermy.hp -= max<int>(1, hero_att - enermy.def);
			while (hero.hp > 0 && enermy.hp > 0) {
				hero.hp -= max<int>(1, enermy.att - hero_def);
				if (hero.hp <= 0) break;
				enermy.hp -= max<int>(1, hero_att - enermy.def);
			}
			if (hero.hp <= 0) {
				hero.hp = 0;
				if (hero.re) {
					hero.hp = hero.max_hp;
					hero.cur_pos = start;
					hero.re = 0;
					hero.acc_cnt--;
				}
				else {
					vector<vector<char>> temp(n, vector<char>(m));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
					}
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) cout << temp[i][j];
						cout << endl;
					}
					cout << "Passed Turns : " << ++t << endl;
					cout << hero << endl;
					cout << "YOU HAVE BEEN KILLED BY " << enermy.name << "..\n";
					return 0;
				}
			}
			else {
				board[enermy.cur_pos.r][enermy.cur_pos.c] = '.';
				monsters.erase(hero.cur_pos);
				if (hero.ex) enermy.exp *= 1.2;
				hero.exp += enermy.exp;
				if (hero.exp >= hero.level * 5) {
					hero.exp = 0;
					hero.level++;
					hero.max_hp += 5;
					hero.hp = hero.max_hp;
					hero.att += 2;
					hero.def += 2;
				}
				if (hero.hr) hero.hp = min<int>(hero.max_hp, hero.hp + 3);
			}
		}
		else if (board[hero.cur_pos.r][hero.cur_pos.c] == 'M') {
			if (hero.hu) hero.hp = hero.max_hp;
			boss_monster enermy = boss;
			bool is_first = true;
			int hero_att = hero.att + hero.add_att;
			int hero_def = hero.def + hero.add_def;
			if (hero.co) {
				if (hero.dx) enermy.hp -= max<int>(1, hero_att * 3 - enermy.def);
				else enermy.hp -= max<int>(1, hero_att * 2 - enermy.def);
			}
			else enermy.hp -= max<int>(1, hero_att - enermy.def);
			while (hero.hp > 0 && enermy.hp > 0) {
				if (hero.hu && is_first) {
					is_first = false;
				}
				else hero.hp -= max<int>(1, enermy.att - hero_def);
				if (hero.hp <= 0) break;
				enermy.hp -= max<int>(1, hero_att - enermy.def);
			}
			if (hero.hp <= 0) {
				hero.hp = 0;
				if (hero.re) {
					hero.hp = hero.max_hp;
					hero.cur_pos = start;
					hero.re = 0;
					hero.acc_cnt--;
				}
				else {
					vector<vector<char>> temp(n, vector<char>(m));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
					}
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) cout << temp[i][j];
						cout << endl;
					}
					cout << "Passed Turns : " << ++t << endl;
					cout << hero << endl;
					cout << "YOU HAVE BEEN KILLED BY " << enermy.name << "..\n";
					return 0;
				}
			}
			else {
				if (hero.ex) enermy.exp *= 1.2;
				hero.exp += enermy.exp;
				if (hero.exp >= hero.level * 5) {
					hero.exp = 0;
					hero.level++;
					hero.max_hp += 5;
					hero.hp = hero.max_hp;
					hero.att += 2;
					hero.def += 2;
				}
				if (hero.hr) hero.hp = min<int>(hero.max_hp, hero.hp + 3);
				vector<vector<char>> temp(n, vector<char>(m));
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
				}
				temp[hero.cur_pos.r][hero.cur_pos.c] = '@';
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) cout << temp[i][j];
					cout << endl;
				}
				cout << "Passed Turns : " << ++t << endl;
				cout << hero << endl;
				cout << "YOU WIN!\n";
				return 0;
			}
		}
		else if (board[hero.cur_pos.r][hero.cur_pos.c] == 'B') {
			box acc = boxes[hero.cur_pos];
			boxes.erase(hero.cur_pos);
			board[hero.cur_pos.r][hero.cur_pos.c] = '.';
			if (acc.type == 'W') {
				hero.add_att = acc.atk;
			}
			else if (acc.type == 'A') {
				hero.add_def = acc.def;
			}
			else {
				if (acc.acc_type == "HR" && hero.hr == false && hero.acc_cnt < 4) {
					hero.hr = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "RE" && hero.re == false && hero.acc_cnt < 4) {
					hero.re = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "CO" && hero.co == false && hero.acc_cnt < 4) {
					hero.co = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "EX" && hero.ex == false && hero.acc_cnt < 4) {
					hero.ex = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "DX" && hero.dx == false && hero.acc_cnt < 4) {
					hero.dx = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "HU" && hero.hu == false && hero.acc_cnt < 4) {
					hero.hu = true;
					hero.acc_cnt++;
				}
				else if (acc.acc_type == "CU" && hero.cu == false && hero.acc_cnt < 4) {
					hero.cu = true;
					hero.acc_cnt++;
				}
			}
		}


		//cout << "==========================\n";
		//vector<vector<char>> temp(n, vector<char>(m));
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
		//}
		//temp[hero.cur_pos.r][hero.cur_pos.c] = '@';
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) cout << temp[i][j];
		//	cout << endl;
		//}
		//dout << "cmd: " << cmds[t] << endl;
		//dout << "Passed Turns : " << t << endl;
		//dout << hero << endl;
		//dout << (hero.hr ? "HR " : "")  << (hero.re ? "RE " : "")\
		//	<< (hero.co ? "CO " : "") << (hero.ex ? "EX " : "")\
		//	<< (hero.dx ? "DX " : "") << (hero.hu ? "HU " : "")\
		//	<< (hero.cu ? "CU " : "") << endl;
		//cout << "==========================\n";

		t++;
	}

	vector<vector<char>> temp(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) temp[i][j] = board[i][j];
	}
	temp[hero.cur_pos.r][hero.cur_pos.c] = '@';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << temp[i][j];
		cout << endl;
	}
	cout << "Passed Turns : " << t << endl;
	cout << hero << endl;
	cout << "Press any key to continue.\n";

	return 0;
}