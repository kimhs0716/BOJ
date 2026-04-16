#include <iostream>
using namespace std;
int main() {
  int N, m, M, T, R;
  cin >> N >> m >> M >> T >> R;
  if(m + T > M){
    cout << "-1\n";
    return 0;
  }
  int c = m;
  int i = 0, t = 0;
  while(i != N){
    t++;
    if(c + T > M){
      c -= R;
      c = c < m ? m : c;
    }
    else{
      c += T;
      i++;
    }
  }
  cout << t << endl;
  return 0;
}