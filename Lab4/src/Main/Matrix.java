package Main;

public class Matrix {
    private int[][]  matrixData;    // integer array to store integer data
    private int rowsNum;    // number of rows
    private int colsNum;    // number of columns

    //constructor1
    public Matrix(int row, int col) {
        /*  constructs a row-by-col matrix with all elements equal to 0;
            if row<=0 then the number of rows of the matrix is set to 3;
            likewise, if col<=0 the number of columns of the matrix is set to 3. */
        rowsNum = (row <= 0) ? 3 : row;
        colsNum = (col <= 0) ? 3 : col; 
        matrixData = new int[rowsNum][colsNum];     //allocates memory for the 2D array
    }

    //constructor2
    public Matrix(int[][] table) {
        /*  constructs a matrix out of the two dimensional array table,
            with the same number of rows, columns, and the same element in each
            position as array table. */
        rowsNum = table.length;
        colsNum = table[0].length;
        matrixData = new int[rowsNum][colsNum]; //allocates memory for the 2D array
        
        //loop to fill the array with values:
        for (int i=0; i<rowsNum; i++)
                for(int j=0; j<colsNum; j++)
                        matrixData[i][j] = table[i][j];
    }
    
    //accessors
    public int getRowsNum() { return rowsNum; }
    public int getColsNum() { return colsNum; }
    public int getElement(int i, int j) throws IndexOutOfBoundsException {
        /*  if i and j are valid indices of this matrix,
            then the element on row i and column j of this matrix
            is returned; otherwise it throws an exception with message "Invalid indexes".*/
        if(i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
            return matrixData[i][j];
        } else {
            throw new IndexOutOfBoundsException("Invalid indicess.");
        }
    }

    //setter
    public boolean setElement(int x, int i, int j) {
        /*  if i and j are valid indexes of this matrix, then the element on  row i and
            column j of this matrix is assigned the value  x and true is returned;
            otherwise false is returned and no change in the matrix is performed */
        if(i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
            matrixData[i][j] = x;
            return true;
        } else {
            return false;
        }
    }

    public Matrix copy() { 
        /*  returns a deep copy of this Matrix */
        return new Matrix(matrixData);
    }

    public void addTo(Matrix m) throws ArithmeticException {
        /*  adds Matrix m to this Matrix; it throws an exception message "Invalid operation"
            if the matrix addition is not defined */
        if(this.rowsNum == m.rowsNum && this.colsNum == m.colsNum) {
            for(int i=0; i<this.rowsNum; i++)
                for(int j=0; j<this.colsNum; j++)
                    this.matrixData[i][j] += m.matrixData[i][j];
        } else {
            throw new ArithmeticException("Invalid operation.");
        }
    }

    public Matrix subMatrix(int i, int j) throws ArithmeticException {
        /*  returns a new Matrix object, which represents a submatrix of this Matrix,
            formed out of rows 0 through i and columns 0 through j;
            the method should first check if values i and j are within the required range,
            and throw an exception if any of them is not. The exception detail message should read: "Submatrix not defined".
            Note: The new object should be constructed in such a way that changes in the new matrix do not affect
            this Matrix. */
        if(i >= 0 && i < rowsNum && j >= 0 && j < colsNum) {
            int[][] subMatrix = new int[i][j];
            for(int p=0; p<i; p++)
                for(int q=0; q<j; q++)
                    subMatrix[p][q] = matrixData[p][q];
            return new Matrix(subMatrix);
        } else {
            throw new ArithmeticException("Submatrix not defined.");
        }
    }

    //method to check if matrix is upper triangular
    public boolean isUpperTr() {
        for(int i=0; i<rowsNum; i++)
            for(int j=0; j<i && j<colsNum; j++) //iterates only below i=j axis
                if(matrixData[i][j] != 0)       //returns false if non-zero value encountered
                    return false;
        return true;    //return true if no non-zeroes found
    }
    
    public static Matrix sum(Matrix[] matArray) throws ArithmeticException {
        if(matArray.length <= 0) {
            throw new ArithmeticException("No matrix to add.");
        } else if(matArray.length == 1) {
            return matArray[0];
        } else {
            int row = (matArray[0]).rowsNum;
            int col = (matArray[0]).colsNum;
            Matrix result = new Matrix(row, col);
            for(int i=0; i<row; i++) {
                result.addTo((matArray[i]).copy());
            }
            return result;
        }
    }
    
    public String toString() {
        /*  returns a string representing the matrix,
            with each row on a line, and the elements in each row being
            separated by 2 blank spaces. */
        String output = new String();   // creates an empty string
        for(int i=0; i<rowsNum; i++) {
            for(int j=0; j<colsNum; j++)
                output += matrixData[i][j] + "  ";
            output += "\n";
        }
        return output;
    }
}
