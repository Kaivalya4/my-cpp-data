/**
Nearly sorted array - gfg practise
-> sorting
-> minheap
-> my idea -
    suppose we sorted first k elements(using insertion sort only) . Then first element is at its correct position
    . No slide the window [2 ..... k+1] . We have to just pick last element and put at its correct position.
   later(edit) -  well doing this much of hectic is of no use as direct implementetion of insertion sort will do the same.
        - while loop of insertion sort will run atmost k times
        [3 ....k+3] -> so if wrong is at k+3 then it will go max upto 3.
        O(nk) complexity
*/
///minheap method
#include <iostream>
#include <queue>

using namespace std;

int arr[100];

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    priority_queue<int , vector<int> , greater<int>> minheap;
        int tracker = 0;
        for(int i=0;i<n;i++)
        {
            minheap.push(arr[i]);
            if(minheap.size() > k)
            {
                arr[tracker++] = minheap.top();
                minheap.pop();
            }
        }
        while(!minheap.empty())
        {
            arr[tracker++] = minheap.top();
            minheap.pop();

        }

	    for(int i=0;i<n;i++)
	    {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}


	return 0;
}
