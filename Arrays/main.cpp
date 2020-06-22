#include <iostream>
using namespace std;
struct Array{
    int arr[20];
    int length;
    int size;
};

void swap(int *p,int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void InsertInSorted(struct Array *A,int data){
    int i = A->length - 1;
    while(A->arr[i]> data){
        A->arr[i+1] = A->arr[i];
        i--;
    }
    A->arr[i+1] = data;
    A->length++;
}
bool isSorted(struct Array A){
    for(int i=0;i<A.length-1;i++){
        if(A.arr[i]>A.arr[i+1]){
            return false;
        }
    }
    return true;
}

void negativeOnLeftSide(struct Array *A){
    int i=0,j=A->length-1;
    while(i<j){
        while(A->arr[i]<0){
            i++;
        }
        while(A->arr[j]>=0){
            j--;
        }
        if(i<j)
            swap(&A->arr[i],&A->arr[j]);
    }
}
void Arrayreverse(struct Array *A){
    int i,j;
    for(i=0,j=A->length-1;i<j;i++,j--){
        swap(&A->arr[i],&A->arr[j]);
    }
}

struct Array* ArrayMerge(struct Array* A,struct Array* B){
    int i,j,k;
    i=j=k=0;
    struct Array* C;
    C=new struct Array;
    while(i<A->length && j<B->length){
        if(A->arr[i]<B->arr[j]){
            C->arr[k++] = A->arr[i++];
        }else{
            C->arr[k++] = B->arr[j++];
        }
    }
    for( ;i<A->length;i++){
        C->arr[k++] = A->arr[i];
    }
    for( ;j<B->length;j++){
        C->arr[k++] = B->arr[j];
    }
    C->length = k;
    C->size = 20;
    return C;

}
struct Array* ArrayUnion(struct Array* A,struct Array* B){
    int i,j,k;
    i=j=k=0;
    struct Array* C;
    C=new struct Array;
    while(i<A->length && j<B->length){
        if(A->arr[i]<B->arr[j]){
            C->arr[k++] = A->arr[i++];
        }else if(A->arr[i]> B->arr[j]){
            C->arr[k++] = B->arr[j++];
        }else if(A->arr[i] == B->arr[j]){
            C->arr[k++] = A->arr[i++];
            j++; // important both need to be implemented
        }
    }
    for( ;i<A->length;i++){
        C->arr[k++] = A->arr[i];
    }
    for( ;j<B->length;j++){
        C->arr[k++] = B->arr[j];
    }
    C->length = k;
    C->size = 20;
    return C;

}

struct Array* ArrayIntersection(struct Array* A,struct Array* B){
    int i,j,k;
    i=j=k=0;
    struct Array* C;
    C=new struct Array;
    while(i<A->length && j<B->length){
        if(A->arr[i]<B->arr[j]){
            i++;
        }else if(A->arr[i]> B->arr[j]){
            j++;
        }else if(A->arr[i] == B->arr[j]){
            C->arr[k++] = A->arr[i++];
            j++; // important both need to be implemented
        }
    }
    C->length = k;
    C->size = 20;
    return C;

}
struct Array* ArrayDifference(struct Array* A,struct Array* B){
    int i,j,k;
    i=j=k=0;
    struct Array* C;
    C=new struct Array;
    while(i<A->length && j<B->length){
        if(A->arr[i]<B->arr[j]){
            C->arr[k++]=A->arr[i++];
        }else if(A->arr[i]> B->arr[j]){
            j++;
        }else if(A->arr[i] == B->arr[j]){
            i++;
            j++; // important both need to be implemented
        }
    }
    for( ;i<A->length;i++){
        C->arr[k++] = A->arr[i];
    }
    C->length = k;
    C->size = 20;
    return C;

}
void Display(struct Array a){
    for(int i=0;i<a.length;i++){
        cout<<a.arr[i]<<" ";
    }
}
int main()
{
    struct Array arr = {{1,3,5,6,7,8,11,14,16},9,20};
    struct Array arr1 = {{2,4,6,8,10,12,14,16},8,20};
    //InsertInSorted(&arr,2);
    //cout<<isSorted(arr)<<"\n";
    //negativeOnLeftSide(&arr);
    struct Array *arr2;
    //arr2 = ArrayMerge(&arr,&arr1);
    //arr2 = ArrayUnion(&arr,&arr1);
    //arr2 = ArrayIntersection(&arr,&arr1);
    arr2 = ArrayDifference(&arr1,&arr);
    Display(*arr2);
    return 0;
}
