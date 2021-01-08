#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int win = 0 ,lose = 0;
struct ch {
	int a,b,c,d;
	long long hash(){
		return this->a*987654 +this->b*95422+this->c*646512+this->d*13464;  
	}
};

map<long long ,bool> x;
void checkA(int a,int b,int c,int d);
int main() {
	char p1,p2,r1,r2;/*
	string xxx = "";
	xxx+=(char)('0'+1);
	cout << xxx << endl;*/
	//cout << win << " "<<lose<< endl;
	while(cin >> p1 >> p2 >> r1 >> r2 && (p1!='0'&&p2!='0'&&r1!='0'&&r2!='0')) {
		win=0;lose=0;
		//cout << win << " "<<lose<< endl;
		checkA(
			(p1=='*'?-1:p1-'0'),
			(p2=='*'?-1:p2-'0'),
			(r1=='*'?-1:r1-'0'),
			(r2=='*'?-1:r2-'0')
		);
		
		int res = win + lose;
		
		if(win==0)cout << 0 << endl;
		else if(lose==0)cout << 1 << endl;
		else {
		cout << win/__gcd(win,win+lose)
			<< "/"
			<< (win+lose)/__gcd(win,win+lose)
			<< endl;		
	}
		//cout << win << " " << lose;
		
	}


	return 0;
}

void checkA(int a,int b,int c,int d){
	/*ch xx;
	xx = {a,b,c,d};
	if(x[xx.hash()]){
		cout << "Go Out!" << xx.hash() << endl;
		return;	
	}
	else x[xx.hash()]=1;*/
	
	/*cout << endl 
		<< "------------" << endl
		<< "Win: " << win << endl
		<<"Lose: " << lose<< endl
		//<<"Hash: " << xx.hash() << endl
		<< "(" << a << "," << b<<","<<c<<","<<d<<")"<<endl
		<< "------------" << endl;*/
		
	
	if(a==-1){
		for(int i=1;i<=6;i++){
			checkA(i,b,c,d);
		}
	}else if(b==-1){
		for(int i=1;i<=6;i++){
			checkA(a,i,c,d);
		}
	}else if(c==-1){
		for(int i=1;i<=6;i++){
			checkA(a,b,i,d);
		}
	}else if(d==-1){
		for(int i=1;i<=6;i++){
			checkA(a,b,c,i);
		}
	}else if(a!=-1&&b!=-1&&c!=-1&&d!=-1){
		//check
		if((c==1&&d==2) || (c==2&&d==1)){
			lose++;
		}else if((a==1&&b==2) || (a==2&&b==1)){
			if((c==1&&d==2) || (c==2&&d==1)){
				lose++;
			}else{
				win++;
			}
		}else if((c==d)&&(a!=b)){
			lose++;
		}else if((a==b)&&(c!=d)){
			win++;
		}else if((c==d)&&(a==b)){
			if(c>=a){
				lose++;
			}else{
				win++;
			}
		}else{
			int AA,BB;
			
			if(a<b)AA=b*10+a;
			else AA=a*10+b;
			
			if(c<d)BB=d*10+c;
			else BB=c*10+d;
			
			if(BB>=AA){
				lose++;
			}else{
				win++;
			}
			
		}
		
	}
	return;
}
