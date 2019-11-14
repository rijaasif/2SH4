package Main;

/* I could organize this better but because
Matrix.java was poorly structured I didn't put the effort
in doing so */

public class UpperTriangularMatrix {
    private int[]  matrixData;  // integer array to store integer data
    private int n;              // size of rows
    
    //constructor
    public UpperTriangularMatrix(int n) {
        this.n = (n <= 0) ? 1 : n;      //if n<=0, set to 1
        int size = this.n*(this.n+1)/2; //sets size of 1D array
        matrixData = new int[size];     //new array, filled with zeroes
    }
    
    //constructor 2
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {
        if(upTriM.getColsNum() == upTriM.getRowsNum()) {    //ensures square matrix
            if(upTriM.isUpperTr()) {                        //ensures upper triangular
                
                this.n = upTriM.getColsNum();           //set row/col length
                this.matrixData = new int[n*(n+1)/2];   //allocates 1D array
                
                /* iterate along upper trianguar matrix and add to 1D array */
                int count = 0;
                for(int i=0; i<n; i++) {
                    for(int j=i; j<n; j++) {
                        this.matrixData[count++] = upTriM.getElement(i, j);
                    }
                }
                
            } else {
                this.n = upTriM.getRowsNum();       //if not upper triangular, still set size
                throw new IllegalArgumentException("Is not upper triangular.");
            }
        } else {
            throw new IllegalArgumentException("Not a square matrix.");
        }
    }
    
    //returns the size of the matrix
    public int getDim() {
        return this.n;
    }
    
    /* ONE DIMENSIONAL INDEX = n*i - i*(i-1)/2 + (j-i) */
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{
        if(i >= 0 && i < n && j >= 0 && j < n) {
            if(j >= i)
                return matrixData[n*i - i*(i-1)/2 + (j-i)]; //converts 2D indices to 1D and returns element
            else
                return 0;                                   //returns if lower triangular specified
        } else {
            throw new IndexOutOfBoundsException("Invalid indices.");
        }
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException{
        if(j < i && x != 0) {                                                   //ensures only 0's are in lower triangle 
            throw new IllegalArgumentException("Incorrect arguments.");
        } else if(i >= 0 && i < n && j >= 0 && j < n) {                         //ensures input is within bounds
            matrixData[n*i - i*(i-1)/2 + (j-i)] = x;                            //assigns to matrix with 2D indices
        } else {
            throw new IndexOutOfBoundsException("Invalid indices.");
        }
    }
    
    public Matrix fullMatrix() {
        Matrix result = new Matrix(n, n);       //uses matrix class to allocate n x n matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j >= i) {                    //if along the upper triangular 
                    result.setElement(matrixData[n*i - i*(i-1)/2 + (j-i)], i, j);
                }
            }
        }
        return result;
    }
    
    /* prints the 1D array in linear form */
    public void print1DArray() {
        for(int i=0; i<n*(n+1)/2; i++)
            System.out.print(matrixData[i] + "  ");
    }
    
    /* converts to a matrix and then prints the values */
    public String toString() {
        Matrix result = fullMatrix();
        String output = new String();   //new string to hold the output
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                output += result.getElement(i, j) + "  ";   //adds each element to the row
            output += "\n";     //new row
        }
        return output;  //returns the string
    }
    
    /* the determinant of triangular matrices is simply the product of the main diagonal */
    public int getDet() {
        int det = 1;    //initialize to 1
        Matrix temp = this.fullMatrix();    //cast the matrix to a full matrix
        for(int i=0; i<this.n; i++) 
            det *= temp.getElement(i, i);   //multiply each element along the main diag
        return det;     //return the determinant
    }
    
    /* this method uses back substitution to solve the system of equations */
    public double[] effSolve(double[] b) throws IllegalArgumentException {
        if(this.getDet() != 0) {            //ensures determinant is non-zero, hence matrix is invertible
            if(this.n == b.length) {        //ensure that matrix rows match length of b
                double[] x = new double[n];
                int lead;
                for(int i=n-1; i>=0; i--) {
                    // n*i - i*(i-1)/2 transforms [i][i] from 2D representation into 1D index
                    lead = matrixData[n*i - i*(i-1)/2];     //this is the leading coefficient of the row
                    x[i] = b[i] / lead;             //everything in the row should be divided by the lead
                    for(int j=n-1; j>i; j--)        //iterates along the row, col to col
                        x[i] -= this.matrixData[n*i - i*(i-1)/2 + (j-i)] * x[j] / lead;     //isolates the current x[i]
                }
                return x;   //returns solutions
            } else {
                throw new IllegalArgumentException("Incompatible vector size.");
            }
        } else { 
            throw new IllegalArgumentException("Determinant is zero.");
        }
    }
    
}
