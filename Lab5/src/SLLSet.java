
public class SLLSet {
    
    SLLNode head;   // the first node  of the linked list
    int size;       // size of linked list
    
    /* constructors */
    public SLLSet() {
        this.head = null;   // beginning is null node
        this.size = 0;      // size of list is 0
    }
    
    public SLLSet(int[] sortedArray) {
        size = sortedArray.length;      // size of list is size of array
        /*  loop iterates from end of sorted array to beginning
            the 'head' of the linked list iteratively gets pushed up */
        head = new SLLNode(sortedArray[size-1], null); // initializes the "head"; after the loop, this node will actually be the 'end'
        for(int i=size-2; i>=0; i--) {
            SLLNode current = new SLLNode(sortedArray[i], head);
            head = current;
        }
    }
    
    /* getter  */
    public int getSize() { return size; }
    
    public SLLSet copy() {
        if(this.head == null) { return new SLLSet(); }   // if the head is null, return empty set
        
        SLLSet copy = new SLLSet();     
        
        SLLNode currentA = this.head;   // current node for original LL
        SLLNode currentB = copy.head;   // current node for copy LL
        
        currentB = new SLLNode(currentA.value, null);   // initializes the head for copy
        while(currentA.next != null) {
            currentA = currentA.next;   // iterate original LL
            currentB.next = new SLLNode(currentA.value, null);  // assign the 'next' 
            currentB = currentB.next;   // iterate copy LL
        }
        
        return copy;    //return the copy
    }
    
    public boolean isIn(int value) {
        SLLNode current = this.head;    // sets current node
        while(current.next != null) {   // reach until end of LL
            if(current.value == value)  // if value matches...
                return true;            // ...return false
            current = current.next; // go to next node
        }
        return false;   // by default return false
    }
    
    public void add(int value) {
        SLLNode current = this.head;
        boolean isIn = false;   // I could call isIn() method, but would cause 2*n runtime
        
        // TODO : ADD WHILE KEEPING THE LIST SORTED
        
        while(current.next != null) {       // iterate until end of LL
            
            if(current.value == value) {    // if value is in LL...
                isIn = true;    //...raise the flag
                break;          //...stop the loop
            }
            
            current = current.next; // go to next node
        }
    }
    
    public void remove(int value) {
        SLLNode current = this.head;
        
        while(current.next != null) {       // iterate until end of LL
            if(current.next.value == value) {    // if next node's value is to be removed...
                current.next = current.next.next;   //...assign the next, next node to current next node
                break;                              //...and stop the loop
            }
            current = current.next; // go to next node
        }
    }
    
    public SLLSet union(SLLSet set) {
        SLLSet union = new SLLSet();
        SLLNode current = union.head;
        SLLNode currentA = this.head;
        SLLNode currentB = set.head;
        
        while(currentA.next != null || currentB.next != null) {
            if(currentA.value < currentB.value) {
                current = new SLLNode(currentA.value, null);
                currentA = currentA.next;
            } else if(currentB.value < currentA.value) {
                current = new SLLNode(currentB.value, null);
                currentB = currentB.next;
            } else {
                current = new SLLNode(currentA.value, null);
                currentA = currentA.next;
                currentB = currentB.next;
            }
            current = current.next;
        }
        
        if(currentA.next == null) {
            while(currentB.next != null) {
                current = new SLLNode(currentB.value, null);
                currentB = currentB.next;
                current = current.next;
            }
        }
        if(currentB.next == null) {
            while(currentA.next != null) {
                current = new SLLNode(currentA.value, null);
                currentA = currentA.next;
                current = current.next;
            }
        }
        
        return union;
    }
    
    public SLLSet intersect(SLLSet set) {
        SLLSet intersect = new SLLSet();
        SLLNode current = intersect.head;
        SLLNode currentA = this.head;
        SLLNode currentB = set.head;
        
        while(currentA.next != null || currentB.next != null) {
            if(currentA.value == currentB.value) {
                current = new SLLNode(currentA.value, null);
            }
            current = current.next;
        }
        
        return intersect;
    }
}
