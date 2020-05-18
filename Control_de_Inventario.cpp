#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
	int Menu , ArticulosN, Posiciones, i, ProductosN = 0;
	int codigoB;//Codigo para modificar los productos.
	char respuesta;//Respuesta para salir del o no del menu
	
	struct Producto {
		string nombre; //Nombre Producto.
		int codigo;//Codigo con el que se indetifica el producto o ID.
		string descripcion;//Descripcion del producto.
		float costoT;//Costo Total por Todos los productos existentes.
		float precioUnidad;//Precio por unidad osea un solo producto.
		int existencia;//Exitencia es el numero de productos que hay.
		string estado;//Estado default del producto mas adelante se cambia si ya no esta en existencia
		int StockMinimo;//Esto es como la cantidad minima que siempre tiene de productos antes que se tenga que rellenar otra vez. 
	} Almacen[300];//Array o vector en el cual se guardaran todos los datos ingresados. 
	
   cout <<"Bienvenido al sistema de inventario"<<endl;
   
   SaltoMenu:
   	
   	for(i=0; i<=ProductosN; i++){
		
		Almacen[i].estado = "Si";// el estado "Si" es que hay productos si es "No" es que no hay producto.
	}
	
   	
   float AlmacenCostoT = 0; //Reinicio de costo total para que el valor sea el indicadicado
   	
   cout <<"\n";
   
   cout <<"**********************MENU**********************"<<endl;
   cout <<"\n";
   cout <<"1 = Introducir un articulo"<<endl;
   cout <<"\n";
   cout <<"2 = Modificar un articulo"<<endl;
   cout <<"\n";
   cout <<"3 = Eliminar un articulo"<<endl;
   cout <<"\n";
   cout <<"4 = Listar o Mostrar Inventario"<<endl;
   cout <<"\n";
   cout <<"5 = Listar o Mostrar Inventario de productos agotados"<<endl;
   cout <<"\n";
   cout <<"6 = Salir del programa"<<endl;
   cout <<"\n";
   
   cout <<"Por favor ingrese el numero del apartado del menu selecionado"<<endl;
   cin>>Menu;
   
   
   switch(Menu){//Menu creado con selector multiple Switch.
   	
   	//Introducir articulo.
   	case 1:
   		SaltoProceso:
   		
   		cout <<"\n";
   		cout <<"**********************Introducir articulo**********************"<<endl;
   		cout <<"\n";
   		
   		cout <<"Por favor coloque la cantidad de articulos a ingresar"<<endl;
   		cin>>ArticulosN;
   		
   		cout <<"\n";
   		
   		for( i = 0; i<ArticulosN; i++){//En todos los bucles for la varible i siempre se resetea y vuelve a cero para hacer elnumero de interaciones embase al la condional.
   			
   			cout <<"Ingrese el nombre del articulo "<<i+1<<endl;
   			cin>>Almacen[Posiciones].nombre;
   			
   			cout <<"Ingrese el codigo del articulo"<<endl;
   			cin>>Almacen[Posiciones].codigo;
   			
   			cout <<"Ingrese un descripcion del producto"<<endl;
   			cin>>Almacen[Posiciones].descripcion;
   			
   			cout <<"Ingrese el precio por unidad"<<endl;
   			cin>>Almacen[Posiciones].precioUnidad;
   			
   			cout <<"Ingrese el numero de productos en existencia"<<endl;
   			cin>>Almacen[Posiciones].existencia;
   			
   			cout <<"Ingrese el stock minimo para reabastecer los productos"<<endl;
   			cin>>Almacen[Posiciones].StockMinimo;
   			
   			cout <<"\n";
   			
   			Almacen[Posiciones].costoT = (Almacen[Posiciones].precioUnidad * Almacen[Posiciones].existencia);
   		    
   		    
   		    Posiciones++;//Posiciones no se resetea se guarda la catidad y luego si ingresamos otraves productos, guarda en la posicion donde nos quedamos. 
		   }
		   
		   ProductosN += ArticulosN;//Es una varible acumulativa que sirve para ver cuantos productos se van metiendo y los va sumando para sacar una catidad.
   			
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		 }else if(respuesta == 'n'){
		 	goto SaltoProceso;
		 }
   		 
   	  break;
   	
   	
   	//Modificar articulo.
   	case 2:
   		 SaltoProceso2:
   		 	
   		cout <<"\n";
   		cout <<"**********************Modificar articulo**********************"<<endl;
   		cout <<"\n";
		   
		cout <<"Introducir codigo del producto para su modificacion"<<endl;
		cin>>codigoB;
		
		cout <<"\n";
		
		for(i=0; i<ProductosN; i++){
			
			if(Almacen[i].codigo == codigoB){//Compara el codigo guardado en el struct con el codigo ingresado en codigoB.
				
			cout <<"Ingrese el nombre del articulo "<<i+1<<endl;
   			cin>>Almacen[i].nombre;
   			
   			cout <<"Ingrese el codigo del articulo"<<endl;
   			cin>>Almacen[i].codigo;
   			
   			cout <<"Ingrese un descripcion del producto"<<endl;
   			cin>>Almacen[i].descripcion;
   			
   			cout <<"Ingrese el precio por unidad"<<endl;
   			cin>>Almacen[i].precioUnidad;
   			
   			cout <<"Ingrese el numero de productos en existencia"<<endl;
   			cin>>Almacen[i].existencia;
   			
   			cout <<"Ingrese el estado de exitencia entre Si y No"<<endl;
   			cin>>Almacen[i].estado;
   			
   			cout <<"Ingrese el stock minimo para reabastecer los productos"<<endl;
   			cin>>Almacen[i].StockMinimo;
   			
   			Almacen[i].costoT = (Almacen[i].precioUnidad * Almacen[i].existencia);
				
		} 	
   		
   	}
   		 cout <<"\n";
   		 
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		}else if(respuesta == 'n'){
			goto SaltoProceso2;
		}
   		 
   		 
   	  break;
   	  
   	  
   	  //Eliminar articulo. <----------------------------------------------------------------------------Nilson Trabajo
   	case 3:
   		
   		 SaltoProceso3:
   		 	
   		cout <<"\n";
   		cout <<"**********************Eliminar articulo**********************"<<endl;
   		cout <<"\n";
   		
   		
   		
   		
   		
   		 
   		 
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		}else if(respuesta == 'n'){
			goto SaltoProceso3;
		}
   		
   	   break;
   	   
   	   
   	  //Listar o Mostrar Inventario.
   	case 4:
   		
   		 SaltoProceso4:
   		
   		
   		cout <<"\n";
   		cout <<"**********************Listar o Mostrar Inventario**********************"<<endl;
   		cout <<"\n";
   		 	
   		for(i = 0; i<ProductosN; i++){//La varible acumulativa Mostrar se ocupa aqui para mostrar el total de articulos guardados exacto; 
   			
   			cout <<"Nombre Articulo:"<<Almacen[i].nombre<<endl;
   			cout <<"Codigo Articulo:"<<Almacen[i].codigo<<endl;
   			cout <<"Descripcion del Articulo:"<<Almacen[i].descripcion<<endl;
   			cout <<"Costo Total del Articulo:$"<<Almacen[i].costoT<<endl;
   			cout <<"Precio por unidad Articulo:$"<<Almacen[i].precioUnidad<<endl;
   			cout <<"Exitencia Articulo:"<<Almacen[i].existencia<<" Articulos"<<endl;
   			cout <<"Estado del Articulo:"<<Almacen[i].estado<<endl;
   			cout <<"Stock Minimo del Articulo:"<<Almacen[i].StockMinimo<<endl;
   			
   			cout <<"\n"; 
   			
   			AlmacenCostoT += Almacen[i].costoT;
   			
		   }
		   
		   
		cout <<"El costo total de todo el Inventario es de:$"<<AlmacenCostoT<<endl;
	    cout <<"\n";    
   		   		 
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		}else if(respuesta == 'n'){
			goto SaltoProceso4;
		}
   		
   	  break;
   	  
   	  
   	  //Listar o Mostrar Inventario de productos agotados.<-------------------------------------------------------------Denis trabajo.
   	case 5:
   		 SaltoProceso5:
   		 	
   		cout <<"\n";
   		cout <<"**********************Listar o Mostrar Inventario de productos agotados**********************"<<endl;
   		cout <<"\n";
   		
   		
   		
   		
   		
   		 
   		 
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		}else if(respuesta == 'n'){
			goto SaltoProceso5;
		}
   		
   	   break;
   	
   	
   	  //Salir del programa.
   	case 6:
   	
   	     goto SaltoSalida;
   		
   		break;
   	
   	default:
   		
   		cout <<"\n";
   		cout <<"Por favor introducir Un numero que concuerde con los del menu"<<endl;
   		
   		goto SaltoMenu;
   		
   		break;
   }
   
   
       SaltoSalida:
   
   system("pause");
   
}
