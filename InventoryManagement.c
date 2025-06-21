#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;

struct item {
	int I_Id;
	char I_Name[50];
	float I_Price;
	int I_Quantity;
	float I_Total;
	struct item *Next;
}*First;

void Add_Item(){
	
	struct item *available;
	struct item *newitem;
	char name[50];
	int quntity;
	float price;
	
	available = (struct item*)malloc(sizeof(struct item));
	
	newitem=available;
	available=available->Next;
	

	newitem->I_Id=101+count;
	printf("Enter Name Of Product :");
	scanf("%s",name);
	strcpy(newitem->I_Name,name);
	printf("Enter Product Quantity :");
	scanf("%d",&quntity);
	newitem->I_Quantity=quntity;
	printf("Enter Product Price :");
	scanf("%f",&price);
	newitem->I_Price=price;
	newitem->I_Total=price*quntity;
	
	newitem->Next=NULL;
	if (First==NULL){
		First=newitem;
	}else{
		struct item *ptr;
		ptr=First;
		while(ptr->Next!=NULL){
			ptr=ptr->Next;
		}
		ptr->Next=newitem;
	}
	count++;
	printf("\"%s\" Item Add Successfully.\n\n",name);
}

void Update_item(){
	if (First==NULL){
		printf("Inventory is Empty.\n");
	}else{
		char name[50];
		int flag=0,i,quantity;
		float price;
		printf("Enter Product Name : ");
		scanf("%s",name);
		struct item *ptr;
		ptr=First;
		for(i=0;i<count;i++){
			if (strcmp(ptr->I_Name,name)){
				ptr=ptr->Next;
			}else{
				printf("Enter New Quantity :");
				scanf("%d",&quantity);
				printf("Enter New Price :");
				scanf("%f",&price);
				ptr->I_Price=price;
				ptr->I_Quantity=quantity;
				ptr->I_Total=ptr->I_Price*ptr->I_Quantity;
				printf("\nNew Information Change Succesfully.\n");
				flag=1;
				break;
			}
		}
		if (flag==0){
			printf("Item Not In Inventory.\n");
		}
	}
}

void Display_Spe_Item_id(){
	if (First==NULL){
		printf("No One Item In Inventory.\n");
	}else{
        int s_id,flag=0;
		printf("Enter Product Id : ");
		scanf("%d",&s_id);
		struct item *ptr;
		ptr=First;
		while(ptr!=NULL){
            if(ptr->I_Id==s_id){
                flag=1;
                break;
            }else{
                ptr=ptr->Next;
            }
		}
		if(flag==1){
			printf("\n------------------------------\n");
			printf("Product Name : %s\nProduct price per product : %.2f \nProduct Quantity : %d \nProduct Total Price : %.2f\n",ptr->I_Name,ptr->I_Price,ptr->I_Quantity,ptr->I_Total);
		}else{
            printf("\n------------------------------\n");
			printf("Product is not found in Inventory.\n");
		}
	}
}


void DeleteItem(){
	if (First==NULL){
		printf("Inventory is Empty.\n");
	}else{
		char name[50];
		int flag=0;
		printf("Enter Product Name : ");
		scanf("%s",name);
		struct item *ptr;
		struct item *preptr;
		ptr=First;
		if(First->Next==NULL){
			if (strcmp(ptr->I_Name,name)){
				printf("Item not in Inventory.\n");
			}else{
				First=NULL;
				free(ptr);
				printf("\nItem Delete Succesfully.\n");
			}
		}else{
			int i;
			for(i=0;i<count;i++){
				if (strcmp(ptr->I_Name,name)){
					preptr=ptr;
					ptr=ptr->Next;
				}else{
					preptr->Next=ptr->Next;		
					printf("\n\"%s\" Item Delete Succesfully.\n",ptr->I_Name);
					free(ptr);
					flag=1;
					break;
				}
			}
			if (flag==0){
				printf("Item Not In Inventory.\n");
			}	
		}
	}
}

void Display_All(){
	if (First==NULL){
		printf("NO item in inventory.\n");
	}else{
	    printf("+------------+--------------------+------------+------------+-----------------+\n");
    	printf("| %-10s | %-18s | %-10s | %-10s | %-15s |\n", "ID", "Product", "Price", "Quantity","Total");
    	printf("+------------+--------------------+------------+------------+-----------------+\n");
    	printf("+------------+--------------------+------------+------------+-----------------+\n");
		struct item *ptr;
    	ptr=First;
		while(ptr!=NULL){
			printf("| %-10d | %-18s | %-10.2f | %-10.2d | %-15.2f |\n",ptr->I_Id,ptr->I_Name,ptr->I_Price,ptr->I_Quantity,ptr->I_Total);
			ptr=ptr->Next;
			printf("+------------+--------------------+------------+------------+-----------------+\n");
		}
	
	}
}

void main (){
	int choice;
	printf("::::Welcome to Inventory Management System::::\n\n");
	while(1){
		printf("0 For Exit \n");
		printf("1 For Add Item \n");
		printf("2 For Update Item \n");
		printf("3 For Display Specific Item Details ID\n");
		printf("4 For Delete Item \n");
		printf("5 For Display All Item \n");
		printf("\nWhat you want to perform:");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				return;
			case 1:
				Add_Item();
				printf("--------------------------------\n");
				break;
			case 2:
				Update_item();
				printf("--------------------------------\n");
				break;
			case 3:
				Display_Spe_Item_id();
				printf("--------------------------------\n");
				break;
			case 4:
				DeleteItem();
				printf("--------------------------------\n");
				break;	
			case 5:
				Display_All();
				printf("--------------------------------\n");
				break;
			default:
				printf("Invaild Choice ReEnter Choice.");
				printf("--------------------------------\n");
		}
	}
}
