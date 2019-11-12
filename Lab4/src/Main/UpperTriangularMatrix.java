package Main;

public class UpperTriangularMatrix {
    private int[]  matrixData;    // integer array to store integer data
    private int n;    // size of rows
    
    //constructor
    public UpperTriangularMatrix(int n) {
        this.n = n = (n <= 0) ? 1 : n;   //if n<=0, set to 1
        int size = this.n*(this.n+1)/2;
        matrixData = new int[size];
    }
    
    //constructor 2
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {
        if(upTriM.getColsNum() == upTriM.getRowsNum()) {
            if(upTriM.isUpperTr()) {
                this.n = upTriM.getColsNum();
                this.matrixData = new int[n*n];
                int count = 0;
                for(int i=0; i<n; i++) {
                    for(int j=i; j<n; j++) {
                        this.matrixData[count++] = upTriM.getElement(i, j);
                    }
                }
            } else {
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
        if(i >= 0 && i < n && j >= 0 && j < n && j >= i) {
            return matrixData[n*i - i*(i-1)/2 + (j-i)];
        } else {
            throw new IndexOutOfBoundsException("Invalid indices.");
        }
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException{
        if(j < i && x != 0) {
            throw new IllegalArgumentException("Incorrect arguments.");
        } else if(i >= 0 && i < n && j >= 0 && j < n && j >= i) {
            matrixData[n*i - i*(i-1)/2 + (j-i)] = x;
        } else {
            throw new IndexOutOfBoundsException("Invalid indices.");
        }
    }
    
    public Matrix fullMatrix() {
        Matrix result = new Matrix(n, n);
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=n-1; j>=i && j>=0; j--)
                result.setElement(matrixData[count++], i, j);
        return result;
    }
    
    public void print1DArray() {
        for(int i=0; i<n*(n+1)/2; i++)
            System.out.print(matrixData[i] + "  ");
    }
    
    public String toString() {
        Matrix result = fullMatrix();
        String output = new String();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                output += result.getElement(i, j) + "  ";
            output += "\n";
        }
        return output;
    }
    
    public int getDet() {
        int det = 1;
        Matrix temp = new Matrix(n, n);
        for(int i=0; i<n; i++) 
            det *= temp.getElement(i, i);
        return det;
    }
    
    public double[] effSolve(double[] b) throws IllegalArgumentException {
        if(this.getDet() != 0) {
            return new double[1];   //WORKING ON IT
        } else {
            throw new IllegalArgumentException("Determinant is zero.");
        }
    }
}
