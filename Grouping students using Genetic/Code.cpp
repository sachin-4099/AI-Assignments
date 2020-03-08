#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<lli>V;
vector<float>V1[10000];
vector<float>final;

int main()
{

  lli i,j,n,d,m,k,l;
  cout<<"Input number of students: ";
  cin>>n;
  cout<<"Input number of subjects: ";
  cin>>m;
  cout<<"Number of groups: ";
  cin>>k;
 
  for(i=0;i<n;i++)
  { lli s=0;
  	cout<<"Marks of student "<<i+1<<": ";
    for(j=0;j<m;j++)
    {cin>>d;
     s+=d;
    }
    s=s/m;
    V.push_back(s);
  }
 

  mt19937 mt_rand(time(NULL));

  lli pop_size=80;

  for(i=0;i<(pop_size);i++)
  {  
    
    lli A[10000]={0};
      
   for(j=1;j<=k;j++)
  { 
    d = (mt_rand() % n);
    if(A[d]==0)
    { A[d]+=1;
      V1[i].push_back(V[d]);
    }
    else
    { while(A[d]>=1)
      d = (mt_rand() % n);
     
      A[d]+=1;
      V1[i].push_back(V[d]);
    }
 
  }
      
 }
 

  for(i=1;i<=100;i++)
  { 
    vector<pair<lli,lli>>V3;
    vector<lli>V4,V5,V6;
    vector<lli>V2[10000];
    vector<float>V7[10000]; 
    
    for(lli h=0; h<(pop_size);h++)  
   {  for(j=0;j<n;j++)
    { lli min = abs(V1[h][0]-V[j]);
      lli min1 = 0;
      for(l=1;l<k;l++)
      {  if(abs(V1[h][l]-V[j])<min)
        { min = abs(V1[h][l]-V[j]);
          min1 = l;
        }
      }
      V2[h].push_back(min1);
    }
   } 
    

     lli s2=0;  

     for(j=0;j<(pop_size);j++)
   { lli s=0;
     for(l=0;l<n;l++)
     s+=(V1[j][V2[j][l]]-V[l])*(V1[j][V2[j][l]]-V[l]); 
     s2+=s;  
     V3.push_back({s,j}); 
   }
   
   sort(V3.begin(),V3.end());  
      
   for(j=0;j<V1[V3[0].second].size();j++)
   {if(i==100)
    final.push_back(V1[V3[0].second][j]);
   }
   reverse(V3.begin(),V3.end());

      
      
   float s1=0;   
   
   for(j=1;j<=(pop_size);j++)
   s1+=j;
      
   for(j=1;j<=(pop_size);j++)
   { float d=(j/s1)*100;
     lli d1=ceil(d);
     
     if((d1-d)>0.5)
     V4.push_back(floor(d));
     else
     V4.push_back(ceil(d));   
   }
   

   V5.push_back(1);
   lli z=V4[0];   
      
   for(j=1;j<V4.size();j++)
   {V5.push_back(z+1);
    z=z+V4[j];
   }
      
 
  for(j=1;j<=(pop_size);j++)
   { d = (rand() % 100)+1;
     
     lli pos=lower_bound(V5.begin(), V5.end(), d)-V5.begin();
     if(pos!=0)
     pos=pos-1;    
     V6.push_back(V3[pos].second);
   }

 
   lli z1=0;    
   for(j=1;j<=((pop_size)/2);j++)
   { d = (rand() % pop_size);
     
     lli d1 =(rand() % pop_size);
     
     lli cnt=0;
     
     while(d1==d && cnt<=60)
     {d1 = (rand() % pop_size);
      cnt++;
     }
    
    
     lli d2 = (rand() % k);

     lli d3 = (rand() % 2);

     map<float,lli>B,C;
    
    if(d3==0)
    { for(l=0;l<=d2;l++)
      { V7[z1].push_back(V1[V6[d1]][l]);
        V7[z1+1].push_back(V1[V6[d]][l]);
      }
     
     for(l=d2+1;l<k;l++)
     {V7[z1].push_back(V1[V6[d]][l]);
      V7[z1+1].push_back(V1[V6[d1]][l]);
     }
    }
    else
    { for(l=d2+1;l<k;l++)
      { V7[z1].push_back(V1[V6[d1]][l]);
        V7[z1+1].push_back(V1[V6[d]][l]);
     
      }
     
     for(l=0;l<=d2;l++)
     {V7[z1].push_back(V1[V6[d]][l]);
      V7[z1+1].push_back(V1[V6[d1]][l]);
     }
    }     
    

    z1+=2;
   }
   
  for(lli h=0;h<(pop_size);h++)
  {V1[h].clear();
   V1[h]=V7[h];
   
  }
      
 
}
    
   vector<lli> groups[k]; 

   for(lli j=0; j<V.size();j++)
   { lli min,min1;
     for(lli i=0; i<final.size(); i++)
    { lli res = abs(final[i]-V[j])*abs(final[i]-V[j]);
       if(i==0)
     {min = res;
      min1 = i;
     }
      if(res < min)
      { min = res;
        min1 = i;
      }
    }
    groups[min1].push_back(j+1);
   }
    
   for(lli i = 0; i<final.size(); i++)
   { cout<<"Group "<<i+1<<": ";
    
     for(lli j=0;j<groups[i].size();j++)
     cout<<groups[i][j]<<" ";
    
     cout<<"\n";
   }
     
       

  return 0;
    
}