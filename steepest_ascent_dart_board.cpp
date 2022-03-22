#include<bits/stdc++.h>

using namespace std;

struct State{
	int x,y,lvl,quadrant;
	State(){
		x=-1;
		y=-1;
		lvl=-1;
		quadrant=-1;
	}
	State(int a,int b,int c,int d){
         x=a;
         y=b;
         lvl=c;
         quadrant=d;
	}
	bool operator==(const State& a) const
   {
    return (x == a.x && y == a.y && lvl==a.lvl && quadrant == a.quadrant);
   }
   bool operator!=(const State& a) const
   {
    return (x != a.x || y != a.y || lvl!=a.lvl || quadrant != a.quadrant);
   }
};

int calculate_heuristic(map<int,State>&mp,map<int,State>&goal){
	int sum=0;
	for(int i=1;i<=12;i++){
		int val=0;
		int delta = abs(mp[i].lvl-goal[i].lvl);
		if(mp[i].quadrant==1){
			if(goal[i].lvl>=mp[i].lvl){
			    val = abs(mp[i].x-delta-goal[i].x)+abs(mp[i].y-delta-goal[i].y);}
			else{
				val = abs(mp[i].x+delta-goal[i].x)+abs(mp[i].y+delta-goal[i].y);
			}
		}
		else if(mp[i].quadrant==2){
			if(goal[i].lvl>=mp[i].lvl){
			    val = abs(mp[i].x-delta-goal[i].x)+abs(mp[i].y+delta-goal[i].y);}
			else{
			    val = abs(mp[i].x+delta-goal[i].x)+abs(mp[i].y-delta-goal[i].y);
			}
		}
		else if(mp[i].quadrant==3){
            if(goal[i].lvl>=mp[i].lvl){
			    val = abs(mp[i].x+delta-goal[i].x)+abs(mp[i].y-delta-goal[i].y);}
			else{
			    val = abs(mp[i].x-delta-goal[i].x)+abs(mp[i].y+delta-goal[i].y);
			}	
		}
		else if(mp[i].quadrant==4){
			if(goal[i].lvl>=mp[i].lvl){
			    val = abs(mp[i].x+delta-goal[i].x)+abs(mp[i].y+delta-goal[i].y);}
			else{
			    val = abs(mp[i].x-delta-goal[i].x)+abs(mp[i].y-delta-goal[i].y);
			}
		}
        
		if(goal[i].lvl==2){
			val/=5;
		}
		else if(goal[i].lvl==1){
			val/=3;
		}
		sum += (val+delta);

	}
  
	return sum;
}

pair<int,map<int,State>> rotate_clockwise(vector<vector<int>>&dart_board,map<int,State>&curr,map<int,State>&goal){
	map<int,State>tmp=curr;
	map<int,State>ans=curr;
	int hval;
	int mn=INT_MAX;

	/*lvl 0*/
	tmp[dart_board[2][2]].y++;
    tmp[dart_board[2][2]].quadrant=2;
    tmp[dart_board[2][3]].x++;
    tmp[dart_board[2][3]].quadrant=4;
    tmp[dart_board[3][3]].y--;
    tmp[dart_board[3][3]].quadrant=3;
    tmp[dart_board[3][2]].x--;
    tmp[dart_board[3][2]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    /*lvl-1*/
    tmp=curr;
    tmp[dart_board[1][1]].y+=3;
    tmp[dart_board[1][1]].quadrant=2;
    tmp[dart_board[1][4]].x+=3;
    tmp[dart_board[1][4]].quadrant=4;
    tmp[dart_board[4][4]].y-=3;
    tmp[dart_board[4][4]].quadrant=3;
    tmp[dart_board[4][1]].x-=3;
    tmp[dart_board[4][1]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    /*lvl-2*/
    tmp=curr;
    tmp[dart_board[0][0]].y+=5;
    tmp[dart_board[0][0]].quadrant=2;
    tmp[dart_board[0][5]].x+=5;
    tmp[dart_board[0][5]].quadrant=4;
    tmp[dart_board[5][5]].y-=5;
    tmp[dart_board[5][5]].quadrant=3;
    tmp[dart_board[5][0]].x-=5;
    tmp[dart_board[5][0]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    return {mn,ans};

}

pair<int,map<int,State>> rotate_anticlockwise(vector<vector<int>>&dart_board,map<int,State>&curr,map<int,State>&goal){
	map<int,State>tmp=curr;
	map<int,State>ans=curr;
	int hval;
	int mn=INT_MAX;

	/*lvl 0*/
	tmp[dart_board[2][2]].x++;
    tmp[dart_board[2][2]].quadrant=3;
    tmp[dart_board[3][2]].y++;
    tmp[dart_board[3][2]].quadrant=4;
    tmp[dart_board[3][3]].x--;
    tmp[dart_board[3][3]].quadrant=2;
    tmp[dart_board[2][3]].y--;
    tmp[dart_board[2][3]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    /*lvl-1*/
    tmp=curr;
    tmp[dart_board[1][1]].x+=3;
    tmp[dart_board[1][1]].quadrant=3;
    tmp[dart_board[4][1]].y+=3;
    tmp[dart_board[4][1]].quadrant=4;
    tmp[dart_board[4][4]].x-=3;
    tmp[dart_board[4][4]].quadrant=2;
    tmp[dart_board[1][4]].y-=3;
    tmp[dart_board[1][4]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    /*lvl-2*/
    tmp=curr;
    tmp[dart_board[0][0]].x+=5;
    tmp[dart_board[0][0]].quadrant=3;
    tmp[dart_board[5][0]].y+=5;
    tmp[dart_board[5][0]].quadrant=4;
    tmp[dart_board[5][5]].x-=5;
    tmp[dart_board[5][5]].quadrant=2;
    tmp[dart_board[0][5]].y-=5;
    tmp[dart_board[0][5]].quadrant=1;
    hval = calculate_heuristic(tmp,goal);
    if(hval<mn){
    	mn=hval;
    	ans=tmp;
    }

    return {mn,ans};
}

pair<int,map<int,State>> jmp(vector<vector<int>>&dart_board,map<int,State>&curr,map<int,State>&goal){

	map<int,State>tmp=curr;
	map<int,State>ans=curr;
	int hval;
	int mn=INT_MAX;
	/*quadrant-1*/	
	  /* lvl-2 <--> lvl-1 */
	  tmp=curr;
	  tmp[dart_board[0][0]].x++;
	  tmp[dart_board[0][0]].y++;
	  tmp[dart_board[0][0]].lvl--;
	  tmp[dart_board[1][1]].x--;
	  tmp[dart_board[1][1]].y--;
	  tmp[dart_board[1][1]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }



	  /* lvl-1 <--> lvl-0 */
	  tmp=curr;
	  tmp[dart_board[1][1]].x++;
	  tmp[dart_board[1][1]].y++;
	  tmp[dart_board[1][1]].lvl--;
	  tmp[dart_board[2][2]].x--;
	  tmp[dart_board[2][2]].y--;
	  tmp[dart_board[2][2]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }





	/*quadrant-2*/
	  /* lvl-2 <--> lvl-1 */
	  tmp=curr;
	  tmp[dart_board[0][5]].x++;
	  tmp[dart_board[0][5]].y--;
	  tmp[dart_board[0][5]].lvl--;
	  tmp[dart_board[1][4]].x--;
	  tmp[dart_board[1][4]].y++;
	  tmp[dart_board[1][4]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }
	  /* lvl-1 <--> lvl-0 */
	  tmp=curr;
	  tmp[dart_board[1][4]].x++;
	  tmp[dart_board[1][4]].y--;
	  tmp[dart_board[1][4]].lvl--;
	  tmp[dart_board[2][3]].x--;
	  tmp[dart_board[2][3]].y++;
	  tmp[dart_board[2][3]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }


	/*quadrant-3*/
	  /* lvl-2 <--> lvl-1 */
	  tmp=curr;
	  tmp[dart_board[5][0]].x--;
	  tmp[dart_board[5][0]].y++;
	  tmp[dart_board[5][0]].lvl--;
	  tmp[dart_board[4][1]].x++;
	  tmp[dart_board[4][1]].y--;
	  tmp[dart_board[4][1]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }

	  /* lvl-1 <--> lvl-0 */
	  tmp=curr;
	  tmp[dart_board[4][1]].x--;
	  tmp[dart_board[4][1]].y++;
	  tmp[dart_board[4][1]].lvl--;
	  tmp[dart_board[3][2]].x++;
	  tmp[dart_board[3][2]].y--;
	  tmp[dart_board[3][2]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }

	/*quadrant-4*/
	  /* lvl-2 <--> lvl-1 */
	  tmp=curr;
	  tmp[dart_board[5][5]].x--;
	  tmp[dart_board[5][5]].y--;
	  tmp[dart_board[5][5]].lvl--;
	  tmp[dart_board[4][4]].x++;
	  tmp[dart_board[4][4]].y++;
	  tmp[dart_board[4][4]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }

	  /* lvl-1 <--> lvl-0 */
	  tmp=curr;
	  tmp[dart_board[4][4]].x--;
	  tmp[dart_board[4][4]].y--;
	  tmp[dart_board[4][4]].lvl--;
	  tmp[dart_board[3][3]].x++;
	  tmp[dart_board[3][3]].y++;
	  tmp[dart_board[3][3]].lvl++;
	  hval = calculate_heuristic(tmp,goal);
	  if(hval<mn){
	  	mn=hval;
	  	ans=tmp;
	  }

	
	return {mn,ans};
}

bool comp(pair<int,map<int,State>>&a,pair<int,map<int,State>>&b){
    return a.first<b.first;
}

int main(){
	vector<vector<int>> dart_board {
		{8,0,0,0,0,12},
		{0,10,0,0,6,0},
		{0,0,3,2,0,0},
		{0,0,9,7,0,0},
		{0,4,0,0,1,0},
		{11,0,0,0,0,5},
	};
	map<int,State>mp;
	mp[dart_board[0][0]]=State(0,0,2,1);
    mp[dart_board[0][5]]=State(0,5,2,2);
	mp[dart_board[1][1]]=State(1,1,1,1);
	mp[dart_board[1][4]]=State(1,4,1,2);
	mp[dart_board[2][2]]=State(2,2,0,1);
	mp[dart_board[2][3]]=State(2,3,0,2);
	mp[dart_board[3][2]]=State(3,2,0,3);
	mp[dart_board[3][3]]=State(3,3,0,4);
	mp[dart_board[4][1]]=State(4,1,1,3);
	mp[dart_board[4][4]]=State(4,4,1,4);
	mp[dart_board[5][0]]=State(5,0,2,3);
	mp[dart_board[5][5]]=State(5,5,2,4);
	map<int,State>goal;
	goal[9]=State(0,0,2,1);
    goal[10]=State(0,5,2,2);
	goal[5]=State(1,1,1,1);
	goal[6]=State(1,4,1,2);
	goal[1]=State(2,2,0,1);
	goal[2]=State(2,3,0,2);
	goal[4]=State(3,2,0,3);
	goal[3]=State(3,3,0,4);
	goal[8]=State(4,1,1,3);
	goal[7]=State(4,4,1,4);
	goal[12]=State(5,0,2,3);
	goal[11]=State(5,5,2,4);
    

    map<int,State>curr = mp;
    int curr_val = calculate_heuristic(curr,goal);
    std::map<int, State> prev;
      std::vector<vector<int>> tmp(6,vector<int>(6));
    tmp=dart_board;
    int cont=0;
    int prev_val;
    while(curr!=goal){
    	cout<<"STATE H_VAL = "<<curr_val<<endl;
    	for(int i=0;i<6;i++){
        	for(int j=0;j<6;j++){
        		cout<<dart_board[i][j]<<" ";
        	}
        	cout<<endl;
        }
    	vector<pair<int,map<int,State>>>succ;
    	succ.push_back(rotate_clockwise(dart_board,curr,goal));
    	succ.push_back(rotate_anticlockwise(dart_board,curr,goal));
    	succ.push_back(jmp(dart_board,curr,goal));
    	sort(succ.begin(),succ.end(),comp);
    	int hval = succ[0].first;
    	if(hval==0){
    		printf("\nGOAL STATE REACHED\n");
    		break;
    	}
    	else{
    		if(hval<=curr_val){
    			curr=succ[0].second;
    			curr_val=hval;
    		}
    		else{
    			printf("\nGOAL STATE UNREACHABLE!\n");
                break;

    		}
    	}
    	
        for(auto i:curr){
        	tmp[i.second.x][i.second.y]=i.first;
            dart_board[i.second.x][i.second.y]=i.first;
        }
       
        cout<<"==============="<<endl;
        cout<<"==============="<<endl;
        if(curr_val==prev_val){
        	cont++;
        	if(cont==6){
        		cout<<"PLATEAU detected"<<endl;
        		break;
        	}
        }
    	
    	prev=curr;
    	prev_val=curr_val;

    }
	return 0;
}
