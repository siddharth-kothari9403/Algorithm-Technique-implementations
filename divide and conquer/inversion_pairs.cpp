#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

void merge(pi arr[], int res[], int const l, int const mid, int const r){
    //first store the halves of the arrays in 2 separate arrays f and s
	pi f[mid-l+1], s[r-mid];

    int n= mid-l+1;
    int m=r-mid;
	
    for (int i=l; i<=mid; i++){
        f[i-l]=arr[i];
    }
    for (int i=mid+1; i<=r; i++){
        s[i-mid-1]=arr[i];
    }
    int i=0, j=0, p=l;
    int count=0;

	while (i<n && j<m){
	
		if (f[i].second<= s[j].second){
            res[f[i].first]+=count;
			arr[p]=f[i]; 
			i++; p++;
		}else{
            // if the right element is less than the left element then we have found a number less than it to the right so increment count
            // keep incrementing until we can assign it back 
			count++;
            arr[p] = s[j];
            p++; j++;
		}
	}
	
	
	while (i<n){
		res[f[i].first]+=count;
		arr[p]=f[i]; 
		i++; p++;
	}

	while (j<m){
        arr[p] = s[j];
        p++; j++;
	}

}

void mergeSort(pi arr[], int res[], int l, int r){
	if (l>=r){
		return;
	} //loop stops when l=r, i.e. only one element left
	int mid= (l+r)/2; 
	mergeSort(arr,res,l,mid); //recursive call on the left half
	mergeSort(arr,res,mid+1,r); //recursive call on the right half
	merge(arr,res,l,mid,r); //merge function to merge the sorted arrays
}


void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    pi arr[n];

    for (int i=0; i<n; i++){
        arr[i]=make_pair(i, a[i]);
    }

    int res[n];

    mergeSort(arr,res,0,n-1);
    printArr(res,n);

    return 0;

}