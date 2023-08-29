#include<bits/stdc++.h>

using namespace std;

int arr[201][201];
int main()
{
	freopen("traffic_control_input.txt", "r", stdin);
    freopen("OutputB_3.txt", "w", stdout);
    int t;
    cin >> t;
    int itr = 0;
    while(t--)
    {
    	int n,m,a,b;
    	cin >> n >> m >> a >> b;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			if(i == n-1 && j == m-1)
    				continue;
    			if(i == 0 && j==m-1)
    				continue;
    			arr[i][j] = 1;
			}
		}
		arr[0][m-1] = b - n  -  m+2 ;
		arr[n-1][m-1] = a - n - m+2; 
		if(arr[0][m-1] <=0 || arr[n-1][m-1] <=0)
			cout << "Case #" << ++itr << ": " << "Impossible" << endl;
		else
			{
				cout << "Case #" << ++itr << ": " << "Possible" << endl;
					for(int i=0;i<n;i++)
    			{
    				for(int j=0;j<m;j++)
    				{
    					cout << arr[i][j] << " " ;
					}				
					cout << endl;
				}
			}
	}
	return 0;
}

    
