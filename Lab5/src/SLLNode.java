
public class SLLNode {
    
    int value;
    SLLNode next;
    
    /* constructor */
    public SLLNode(int value, SLLNode next) {
        this.value = value;
        this.next = next;
    }
    
    /* getters */
    public int getValue() { return this.value; }
    public SLLNode getNext() { return this.next; }
    
    /* setters */
    public void setValue(int value) { this.value = value; }
    public void setNext(SLLNode next) {this.next = next;}
    
}
