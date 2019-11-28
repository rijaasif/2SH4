
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
            SLLNode temp = new SLLNode(sortedArray[i], head);
            head = temp;
        }
    }
    
    /* getter  */
    public int getSize() { return size; }
    
    public SLLSet copy() {
        /* special case if LL is null */
        if(this.head == null) { return null; }
        
        SLLNode current = this.head;    // set a node for current
        int n = this.size;              // variable for size of LL
        int[] copyValues = new int[n];  // array to store values of LL
        
        for(int i=0; i<n; i++) {    // put the values of LL in an array
            copyValues[i] = current.value;
            current = current.next;
        }
        
        return new SLLSet(copyValues);  // return a new SSLSet with same values
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
    
    // I can just do null return statements to simplify this
    public void add(int value) {
        SLLNode current = this.head;    // the current node
        
        /* only occurs if value is smaller than sart (prepend to start) */
        if(value < current.value) {     // check if add to start of LL
            SLLNode newHead = new SLLNode(value, current);  // make a new head
            this.head = newHead;    // assign instance variable to new head
            this.size++;    // increment size of LL
            return;
        }
        
        /* if the value is inserted in the middle of LL  */
        while(current.next != null) {       // iterate until end of LL
            if(current.value == value) {    // if value is in LL...
                return;
            } else if(current.next.value > value) {     // this ensures that value is added in sorted order
                SLLNode temp = new SLLNode(value, current.next);    // temp node that points to next node
                current.setNext(temp);  // current node points to temp node, completing the link
                this.size++;        // increment size of LL by one
                return;
            }
            current = current.next; // iterate through LL
        }
        
        /* only occurs if the value is larger than data in LL (appends to endt) */
        current.next = new SLLNode(value, null);
        this.size++;    // increment size of LL
    }
    
    public void remove(int value) {
        /* case if the LL is null/empty */
        if(this.head == null) { return; }
        
        /* if first node is to be removed */
        if(this.head.value == value) {      // if head equals value
            this.head = this.head.next;     // set next as new head
            this.size--;    // decrement size of LL
            return;     // exit method
        }
        
        /* if last or middle node is to be removed */
        SLLNode current = this.head;    // current node
        while(current.next != null) {   // iterate until end of LL
            if(current.next.value == value) {    // if next node's value is to be removed...
                current.next = current.next.next;   //...assign the next, next node to current next node
                this.size--;    // decrement size of LL
                return;         // exit method
            }
            current = current.next; // go to next node
        }
    }
    
    public SLLSet union(SLLSet set) {
        /* special cases if either LL is empty */
        if(this.head == null) { return set; }   // if either set is empty, the union is the other set
        if(set.head == null) { return this; }
        
        SLLSet union = new SLLSet();    // new LL for the union set
        SLLNode currentA = this.head;   // current node for set A (this set)
        SLLNode currentB = set.head;    // current node for set B (given set)
        
        /* initializes the head */
        if (currentA.value < currentB.value) {              // if A is less than B...
            union.head = new SLLNode(currentA.value, null);     // ...set head
            currentA = currentA.next;                           // ...iterate up A
        } else if (currentB.value < currentA.value) {       // if B is less than A...
            union.head = new SLLNode(currentB.value, null);     // ...set head
            currentB = currentB.next;                           // ...iterate up B
        } else {                                            // A equals B...
            union.head = new SLLNode(currentA.value, null);     // ...set head
            currentA = currentA.next;                           // ...iterate up both A and B
            currentB = currentB.next;
        }
        union.size++;   // increment size of union set
        
        SLLNode current = union.head;   // current node for union LL
        
        /* iterates through rest of the sets, up to the shortest one */
        while(currentA != null && currentB != null) {
            if (currentA.value < currentB.value) {                  // if A < B...
                current.next = new SLLNode(currentA.value, null);   // ...append to U
                currentA = currentA.next;   // ...iterate up A
                union.size++;               // ...increment size of union set
            } else if (currentB.value < currentA.value) {           // if B < A...
                current.next = new SLLNode(currentB.value, null);   // ...append to U
                currentB = currentB.next;   // ...iterate up B
                union.size++;               // ...increment size of union set
            } else {                                                // if B = A...
                current.next = new SLLNode(currentA.value, null);   // ...append to U
                currentA = currentA.next;   // ...iterate BOTH A and B
                currentB = currentB.next;
                union.size++;               // ...increment size of union set
            }
            current = current.next;
        }
        
        /* iterates through the larger list and adds the rest */
        while(currentB != null) {
            current.next = new SLLNode(currentB.value, null);
            currentB = currentB.next;
            current = current.next;
            union.size++;
        }
        while(currentA != null) {
            current.next = new SLLNode(currentA.value, null);
            currentA = currentA.next;
            current = current.next;
            union.size++;
        }
        
        return union;   // return the resultant union
    }
    
    public SLLSet intersection(SLLSet set) {
        /* special cases if either LL is empty */
        if(this.head == null) { return new SLLSet(); }      // if either set is empty, there is no intersect
        if(set.head == null) { return new SLLSet(); }
        
        SLLSet intersect = new SLLSet();    // create new set to store intersect
        SLLNode currentA = this.head;       // current node for set A (this set)
        SLLNode currentB = set.head;        // current node for set B (given set)
        
        /* initialize the head of intersection set */
        while(currentA != null && currentB != null) {
            if (currentA.value < currentB.value) {      // if A < B...
                currentA = currentA.next;               // ...iterate A 
            } else if (currentB.value < currentA.value) {   // if B < A...
                currentB = currentB.next;                   // ...iterate B
            } else {                                                    // if A = B...
                intersect.head = new SLLNode(currentA.value, null);     // ...set the head to value
                currentA = currentA.next;                               // ...iterate both A and B
                currentB = currentB.next;
                intersect.size++;           // ...increment size of intersect
                break;  // ...exit loop
            }
        }
        
        SLLNode current = intersect.head;   // assign current node for intersect head
        
        /* iterates through rest of the list, up to the shorter one */
        while(currentA != null && currentB != null) {
            if (currentA.value < currentB.value) {              // iterates until match is found, similar to head initialization
                currentA = currentA.next;
            } else if (currentB.value < currentA.value) {
                currentB = currentB.next;
            } else {                                                // if A = B...
                current.next = new SLLNode(currentA.value, null);   // ...append to intersection
                current = current.next;                             // ...iterate all lists
                currentA = currentA.next;
                currentB = currentB.next;
                intersect.size++;               // ...increment size
            }
        }
        
        return intersect;
    }
    
    public SLLSet difference(SLLSet set) {
        /* special cases if either LL is empty */
        if(this.head == null) { return new SLLSet(); }  // if this set is null, return empty set
        if(set.head == null) { return this; }           // if the given set is null, return this set
        
        SLLSet difference = this.copy();                // initialize difference with *this* set
        SLLSet intersect = this.intersection(set);      // initialize intersect of both sets
        
        /* essentially performs A - (A∩B) (A is this set, B is given set) */
        SLLNode current = intersect.head;       // set current to intersect
        while(current != null) {                // iterate until end of intersect
            difference.remove(current.value);   // SUBTRACT intersect from difference
            current = current.next;     // iterate
        }
        
        return difference;  // return resultant difference
    }
    
    public static SLLSet union(SLLSet[] sArray) {
        SLLSet result = new SLLSet();   // list set to store result of unions
        for(int i=0; i<sArray.length; i++) {    // iterate through array of linked lists
            result = result.union(sArray[i]);   // perform union of each array with result
        }
        return result;
    }
    
    public String toString() {
        /* special case for empty set */
        if(this.head == null) { return "EMPTY"; }
        
        String list = "";   // variable to store string of values
        SLLNode current = this.head;    // current node for this list
        
        /* iterate to end of list and keep adding value to string */ 
        while(current != null) {
            list += current.value;
            if(current.next != null)    // don't add comma at end
                list += ",";
            current = current.next;
        }
        
        return list;    // return the string
    }
}
