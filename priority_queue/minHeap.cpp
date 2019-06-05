#include <vector>

/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    
    int removeMin() {
        // Complete this function
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = ans;
        
        pq.pop_back();
        
        int parentIndex = 0;
        
        
        int leftCI = (2*parentIndex) + 1;
        int rightCI = (2*parentIndex) + 1;
        
        while(leftCI < pq.size() && rightCI <pq.size()){
            
            int minIndex = min(leftCI, rightCI);
            //swap(pq[minIndex], pq[parentIndex]);
            
            //check for the smaller value
            if(pq[parentIndex] < pq[minIndex]){
                break;
            }else{
            
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = minIndex;
            
            
            leftCI = (2*parentIndex) + 1;
            rightCI = (2*parentIndex) + 1;
            
            }
        }
        
        return ans;
    }
    
    
};

