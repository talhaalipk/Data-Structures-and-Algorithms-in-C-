void binarySearch(int arr[], int start, int end, int key)
{
    if(start > end)
    {
        cout << "------------- Number do not found -------------" << endl ;
        return ;
    }
        
    int mid = start +( end - start )/ 2 ;

    if(arr[mid] == key)
    {
        cout << "------------- Found : " << mid << " Index -------------" << endl ;
        return ;
    }

    //recursion
    if(key < arr[mid])
    {
        end = mid -1 ;
        binarySearch(arr,start , end , key) ;
    }
    else
    {
        start = mid + 1 ;
        binarySearch(arr,start , end , key) ;
    }
    
}