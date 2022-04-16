#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int cap;
vector<pair<int,vector<pair<int,int>>>> book;
void ins(int sz,int pr){
	bool yon=false;
	for(auto &i: book){
		if (i.ff>=sz){
			yon=true;
			i.ff-=sz;
			i.ss.push_back({pr,sz});
			break;
		}
	}
	if (!yon){
		vector<pair<int,int>> temp;
		temp.push_back({pr,sz});
		book.push_back({cap-sz-4,temp});
	}
}
void display(){
	cout<<book.size()<<' ';
	for(auto &i: book) cout<<i.ss.size()<<' ';
	cout<<endl;
}
void search(int x){
	bool yon=false;
	for(int i=0;i<book.size();i++){
		if (yon==true) break;
		for(int j=0;j<book[i].ss.size();j++){
			if (book[i].ss[j].ff == x){
				yon=true;
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	if (!yon) cout<<-1<<' '<<-1<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>cap;
	cap-=16;
	while(true){
		int x;
		cin>>x;
		if (x==1){
			int sz,pr;
			cin>>sz>>pr;
			ins(sz,pr);
			
		}else if(x==2){
			display();
		}else if(x==3){
			int y;
			cin>>y;
			search(y);
		}else break;
	}
}
