#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bitset<20>col,diag1,diag2;
lli board[10][10];
priority_queue<pair<lli,pair<lli,lli>>>open;
queue<pair<lli,pair<lli,lli>>>close;

void printsol(lli n)
{ for(lli i=0;i<n;i++)
 { for(lli j=0;j<n;j++)
   cout<<board[i][j];
   cout<<"\n";
 }

}
    

    
void queensolve(lli r,lli n,lli &ans,lli &val)
{ if(r==n)
 { ans++;
   printsol(n);
   cout<<"\n";
   return;
 }  
    
    
      for(lli c=0;c<n;c++)
    { if(col[c]==0 && diag1[r-c+(n-1)]==0 && diag2[r+c]==0)
      {open.push({val+1,{r,c}});
       pair<lli,pair<lli,lli>>pq=open.top();
       lli z=pq.first;
       lli z1=pq.second.first;
       lli z2=pq.second.second;
       open.pop();  
       close.push({z,{z1,z2}});
       col[c]=diag1[r-c+(n-1)]=diag2[r+c]=board[r][c]=1;
       queensolve(r+1,n,ans,z);
       col[c]=diag1[r-c+(n-1)]=diag2[r+c]=board[r][c]=0;
       
      }
            
      else
      { open.push({val+2,{r,c}});
        open.pop();
      }
          
     
    }
     
        



}


int main()
{ lli ans=0,val=0;

  queensolve(0,8,ans,val);    
  
  cout<<ans;
    
    
}