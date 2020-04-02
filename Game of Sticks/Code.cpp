#include <bits/stdc++.h>
using namespace std;
#define lli long long int

map<pair<lli,lli>,lli>states;


lli minimax(lli n,lli player,lli num,lli alpha,lli beta)
{
  
  if(n==2 || n==3 || n==4) 
  { if(player==1)
    return 1;
    else
    return -1;    
  }
      
  

  if(player==1)   
  { 
    lli bestval=-5000;  
    for(lli i=1;i<=3;i++)
    { lli val;
      if(states[{n-i,2}]==0)
     {val=minimax(n-i,2,num+1,alpha,beta);
      states[{n-i,2}]=val;
     }
      else
      val=states[{n-i,2}];    
      bestval=max(bestval,val);
      alpha=max(alpha,bestval);
      if(beta<=alpha)
      { 
          break;
      }
    }
    return bestval;
  }
    
  else
  { 
    lli bestval=5000;  
    for(lli i=1;i<=3;i++)
    { lli val;
        if(states[{n-i,1}]==0)
     {val=minimax(n-i,1,num+1,alpha,beta);
      states[{n-i,1}]=val;
     }
      else
      val=states[{n-i,1}];   
      bestval=min(bestval,val);
      beta=min(beta,bestval);
      if(beta<=alpha)
      { 
        break;
      } 
    } 
    return bestval;
  }    
      
    
  
    
}


void aivshuman(lli n,lli player)
{
   

  

  if(player==1)   
  { lli sticks;
    cout<<"Your Turn: ";
    cin>>sticks;
    if(sticks==1)
    cout<<"Human picks "<<sticks<<" stick\n";
    else
    cout<<"Human picks "<<sticks<<" sticks\n";
     
    cout<<"Sticks left: "<<n-sticks<<"\n";
    
    if((n-sticks)<=0)
    {cout<<"AI WINS\n";
     return;
    }

    aivshuman(n-sticks,2);   
    return;
  }
      
  if(player==2)   
  { lli res;
    if(n==1)
    {
     cout<<"AI picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     cout<<"Human WINS\n";
     return;
    }
    if(n==2)
    {
     cout<<"AI picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     aivshuman(n-1,1);
     return;
    }
     if(n==3)
    {
     cout<<"AI picks 2 sticks\n";
     cout<<"Sticks left: "<<n-2<<"\n";
     aivshuman(n-2,1);
     return;
    }

     if(n==4)
    {
     cout<<"AI picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     aivshuman(n-3,1);
     return;
    } 


    res=minimax(n-1,1,0,-5000,5000);

    if(res==-1)
    { cout<<"AI picks 1 stick\n";
      cout<<"Sticks left: "<<n-1<<"\n";
      aivshuman(n-1,1);  
      return;
    }

    res=minimax(n-2,1,0,-5000,5000);

    if(res==-1)
    { cout<<"AI picks 2 sticks\n";
      cout<<"Sticks left: "<<n-2<<"\n";
      aivshuman(n-2,1);  
      return;
    }

    res=minimax(n-3,1,0,-5000,5000);

    if(res==-1)
    { cout<<"AI picks 3 sticks\n";
      cout<<"Sticks left: "<<n-3<<"\n";
      aivshuman(n-3,1);  
      return;
    }

    cout<<"AI picks 1 stick\n";
    cout<<"Sticks left: "<<n-1<<"\n";
    aivshuman(n-1,1);  
    return;
     

  }



  
    
  
    
}


void moves(lli n,lli player)    
{ 



  if(player == 1)
  { if(n==1)
    {
     cout<<"Player 1 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     return;
    }
    if(n==2)
    {
     cout<<"Player 1 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     moves(n-1,2);
     return;
    }
     if(n==3)
    {
     cout<<"Player 1 picks 2 sticks\n";
     cout<<"Sticks left: "<<n-2<<"\n";
     moves(n-2,2);
     return;
    }

     if(n==4)
    {
     cout<<"Player 1 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,2);
     return;
    }




    if(states[{n-1,2}]==1)
    {cout<<"Player 1 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     moves(n-1,2);
     return;
    }

    if(states[{n-2,2}]==1)
    {cout<<"Player 1 picks 2 sticks\n";
     cout<<"Sticks left: "<<n-2<<"\n";
     moves(n-2,2);
     return;
    }

    if(states[{n-3,2}]==1)
    {cout<<"Player 1 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,2);
     return;
    }

     cout<<"Player 1 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,2);    
     return;
  }

   if(player == 2)
  { if(n==1)
    {
     cout<<"Player 2 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     return;
    }
    if(n==2)
    {
     cout<<"Player 2 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     moves(n-1,1);
     return;
    }
     if(n==3)
    {
     cout<<"Player 2 picks 2 sticks\n";
     cout<<"Sticks left: "<<n-2<<"\n";
     moves(n-2,1);
     return;
    }

     if(n==4)
    {
     cout<<"Player 2 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,1);
     return;
    }



    if(states[{n-1,1}]==-1)
    {cout<<"Player 2 picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     moves(n-1,1);
     return;
    }

    if(states[{n-2,1}]==-1)
    {cout<<"Player 2 picks 2 sticks\n";
     cout<<"Sticks left: "<<n-2<<"\n";
     moves(n-2,1);
     return;
    }

    if(states[{n-3,1}]==-1)
    {cout<<"Player 2 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,1);
     return;
    }

     cout<<"Player 2 picks 3 sticks\n";
     cout<<"Sticks left: "<<n-3<<"\n";
     moves(n-3,1);    
     return;
  }


  
   


}




int main()
{
  lli d,res,n;
  srand(time(0));
  cout<<"1) AI vs AI\n";
  cout<<"2) AI vs Human\n";
 
  cout<<"Enter your choice: ";
  cin>>d;
  cout<<"\n";

  if(d==1)
 {  
  cout<<"Number of sticks: ";  
  cin>>n;
  cout<<"\n";
  
  lli d1 = rand()%2;

  if(d1==0)
  { cout<<"Player 1 chooses Heads\n";
    cout<<"Tossing the coin: ";
    lli d2 = rand()%2;
    lli player=0;

    if(d2==0)
    {cout<<"Heads it is\n";
     cout<<"Player 1 wins the toss\n\n";
     player=1;
    }  
    else
    {cout<<"Tails it is\n";
     cout<<"Player 2 wins the toss\n\n";
     player=2;
    } 

   if(n==1)
   { cout<<"Player "<<player<<" picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     
     if(player==1)
     cout<<"Player 2 wins\n";
     else
     cout<<"Player 1 wins\n"; 

   }

   else if(n>=2) 
   { res=minimax(n,player,0,-5000,5000);
     moves(n,player);    
     if(res==1)
     cout<<"Player 1 WINS\n";
     else
     cout<<"Player 2 WINS\n";
   }

 }

 else if(d1==1)
  { cout<<"Player 1 chooses Tails\n";
    cout<<"Tossing the coin: ";
    lli d2 = rand()%2;
    lli player=0;

    if(d2==0)
    {cout<<"Heads it is\n";
     cout<<"Player 2 wins the toss\n\n";
     player=2;
    }  
    else
    {cout<<"Tails it is\n";
     cout<<"Player 1 wins the toss\n\n";
     player=1;
    } 

   if(n==1)
   { cout<<"Player "<<player<<" picks 1 stick\n";
     cout<<"Sticks left: "<<n-1<<"\n";
     
     if(player==1)
     cout<<"Player 2 WINS\n";
     else
     cout<<"Player 1 WINS\n"; 

   }

   else if(n>=2) 
   { res=minimax(n,player,0,-5000,5000);
     moves(n,player);    
     if(res==1)
     cout<<"Player 1 WINS\n";
     else
     cout<<"Player 2 WINS\n";
  
   }
         
   }

 }
     
 
  else if(d==2)
  {   cout<<"Number of sticks: ";  
      cin>>n;
      cout<<"\n";

      cout<<"Enter your choice: 1)Heads 2)Tails: ";
      lli d1;
      cin>>d1;
      if(d1==1)
      cout<<"Human chooses Heads\n";
      else
      cout<<"Human chooses Tails\n";  

      if(d1==1)
      { cout<<"Tossing the coin: ";
        lli d2 = rand()%2;
        lli player=0;

       if(d2==0)
      {cout<<"Heads it is\n";
       cout<<"Human wins the toss\n\n";
       player=1;
      }  
      else
      {cout<<"Tails it is\n";
       cout<<"AI wins the toss\n\n";
       player=2;
      }

      aivshuman(n,player);
      }  


      else
      { cout<<"Tossing the coin: ";
        lli d2 = rand()%2;
        lli player=0;

       if(d2==0)
      {cout<<"Heads it is\n";
       cout<<"AI wins the toss\n\n";
       player=2;
      }  
      else
      {cout<<"Tails it is\n";
       cout<<"Human wins the toss\n\n";
       player=1;
      }

      aivshuman(n,player);
      }  



    }


   
  return 0;   
}
