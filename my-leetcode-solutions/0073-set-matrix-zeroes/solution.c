void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int row[m];
    int column[n];

    for(int i=0; i<m; i++){
        row[i]=0;
    }

    for(int i=0; i<n; i++){
        column[i]=0;
    }

    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
            if(matrix[i][j]==0){
               row[i]=1;
               column[j]=1;
            }
        }
    }

    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
            if(row[i]==1 || column[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}
