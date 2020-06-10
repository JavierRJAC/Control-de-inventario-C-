#include<iostream>
#include<stdio.h>
#include<string.h>

//Programa para mantener un control sobre el inventario de cualquier empresa.

using namespace std;

int main()
{
	int Menu , ArticulosN, Posiciones, i, ProductosN = 0, id= 1;
	int codigoB;//Codigo para modificar los productos.
	char respuesta;//Respuesta para salir del o no del menu
	
	struct Producto 
	{
		string nombre; //Nombre Producto.
		int codigo;//Codigo con el que se indetifica el producto o ID.
		char descripcion[200];//Descripcion del producto.
		float costoT;//Costo Total por Todos los productos existentes.
		float precioUnidad;//Precio por unidad osea un solo producto.
		int existencia;//Exitencia es el numero de productos que hay.
		int vendidos;//Es para el numero de productos vendidos y luego restarlo por la existencia y compararlo con el stock minimo.
		string estado;//Estado entre activo y inactivo para poder borrar un elemnto logicamente
		int StockMinimo;//Esto es como la cantidad minima que siempre tiene de productos antes que se tenga que rellenar otra vez. PD: esto ocuparemos para comparar y crear la lista de Productos agotados.
	} Almacen[300];//Array o vector en el cual se guardaran todos los datos ingresados. 
	
   cout <<"Bienvenido al sistema de inventario"<<endl;
   
   SaltoMenu:
	
   	
   float AlmacenCostoT = 0; //Reinicio de costo total para que el valor sea el indicado
   	
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
   
   cout <<"Por favor ingrese la opcion que ha selecionado"<<endl;
   cin>>Menu;
   
   
   switch(Menu){//Menu creado con selector multiple Switch.
   	
   	//Introducir articulo. <----------------------------------------------------------------------------Trabajo Javier.
   	case 1:
   		SaltoProceso:
   		
   		cout <<"\n";
   		cout <<"**********************Introducir articulo**********************"<<endl;
   		cout <<"\n";
   		
   		cout <<"Por favor coloque la cantidad de articulos a ingresar"<<endl;
   		cin>>ArticulosN;//aqui se guarda la cantidad de articulos ingresados
   		
   		cout <<"\n";
   		
   		for( i = 0; i<ArticulosN; i++){//En todos los bucles for la varible i siempre se resetea y vuelve a cero para hacer elnumero de interaciones embase al la condional.
   			
   			cout <<"Ingrese el nombre del articulo "<<i+1<<endl;
   			cin>>Almacen[Posiciones].nombre;
   			
   			cout <<"Ingrese un descripcion del producto"<<endl;
   			cin.ignore();
   			cin.getline(Almacen[Posiciones].descripcion,200);
   			
   			cout <<"Ingrese el precio por unidad"<<endl;
   			cin>>Almacen[Posiciones].precioUnidad;
   			
   			cout <<"Ingrese el numero de productos en existencia"<<endl;
   			cin>>Almacen[Posiciones].existencia;
   			
   			cout <<"Ingrese el stock minimo para reabastecer los productos"<<endl;
   			cin>>Almacen[Posiciones].StockMinimo;
   			
   			cout <<"\n";
   			
   			Almacen[Posiciones].estado = "activo";// el estado "Si" es que hay productos si es "No" es que no hay producto.
   			
   			Almacen[Posiciones].costoT = (Almacen[Posiciones].precioUnidad * Almacen[Posiciones].existencia);
   		    
   		    Almacen[Posiciones].codigo = id;//Codigo por medio de id;
   		    
   		    id++;//Contador para que id sea diferenete
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
   	
   	
   	//Modificar articulo. <----------------------------------------------------------------------------Trabajo Javier.
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
   			
   			cout <<"Ingrese una descripcion del producto"<<endl;
   			cin.ignore();
   			cin.getline(Almacen[i].descripcion,200);
   			
   			cout <<"Ingrese el precio por unidad"<<endl;
   			cin>>Almacen[i].precioUnidad;
   			
   			cout <<"Ingrese el numero de productos en existencia"<<endl;
   			cin>>Almacen[i].existencia;
   			
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
   		//bloque de codigo para elimiar producto
   		cout<<"Ingrese el identificador del producto para su eliminacion"<<endl;
   		cin>>codigoB;//almacena el id
   		
   		for(i=0; i<ProductosN; i++)//recorre la estructura en busca del id
		   {
   				if(Almacen[i].codigo == codigoB)
				   {
					Almacen[i].estado = "inactivo";//por medio del id le asigna al producto la inactividad
					}	
			}
			cout <<"\n";
			cout <<"Eliminacion Completada con !exito!"<<endl;
		
		cout <<"\n";
   		cout <<" ¿Desea Mostrar Inventario Si = s o NO = n ?"<<endl;//pregunta si desea mostrar el menu
   		 cin >>respuesta;
   		cout <<"\n";
   		 
   		 if(respuesta == 's')
			{
   		 		for(i = 0; i<ProductosN; i++)
			   {
   			
   				if(Almacen[i].estado == "activo")//filtra el estado de los productos activos
			 	 	{	
			 	 		cout<<"---------------Listado de Productos existentes---------------\n";
   						cout <<"Nombre Articulo:"<<Almacen[i].nombre<<endl;
   						cout <<"Codigo Articulo:"<<Almacen[i].codigo<<endl;
   						cout <<"Descripcion del Articulo:"<<Almacen[i].descripcion<<endl;
   						cout <<"Costo Total del Articulo:$"<<Almacen[i].costoT<<endl;
   						cout <<"Precio por unidad Articulo:$"<<Almacen[i].precioUnidad<<endl;
   						cout <<"Exitencia Articulo:"<<Almacen[i].existencia<<" Articulos"<<endl;
   						cout <<"Estado del Articulo:"<<Almacen[i].estado<<endl;
   						cout <<"Stock Minimo del Articulo:"<<Almacen[i].StockMinimo<<endl;
   						cout <<"\n"; 
   		  		 	}
				}
			}
		else if(respuesta == 'n')
			{
				goto SaltoMenu;
				break;
			}
   		cout <<"\n";
   		
   	
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's')
			{
   		 		goto SaltoMenu;
			}
		else if(respuesta == 'n')
			{
				goto SaltoProceso3;
			}
   		
   	   break;
   	   
   	   
   	  //Listar o Mostrar Inventario. <----------------------------------------------------------------------------Trabajo Javier.
   	case 4:
   		
   		 SaltoProceso4:
   		
   		
   		cout <<"\n";
   		cout <<"**********************Listar o Mostrar Inventario**********************"<<endl;
   		cout <<"\n";
   		 	
   		for(i = 0; i<ProductosN; i++)
		   {//La varible acumulativa Mostrar se ocupa aqui para mostrar el total de articulos guardados exacto; 
   			
   			if(Almacen[i].estado == "activo")
			   {
   			
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
   		//codigo para mostrar la cantidad de productos agotados
   		int vendidosLocal;
   		char preguntaL;
   		
   		cout <<"¿Quiere mostrar el inventario de productos agotados o ingresar cantidad de productos venidos? Inventario = i y Productos vendidos = p"<<endl;
   		cin>>preguntaL;
   		
   		if(preguntaL == 'p'){
   		cout <<"\n";
   		cout<<"ingrese el Identificador del producto para ingreso de productos vendidos"<<endl;
   		cin>>codigoB;
   		cout<<"ingrese la cantidad de productos vendidos"<<endl;
   		cin >> vendidosLocal;
		cout<<"\n";
			for(i=0; i<ProductosN; i++)//recorre la estructura en busca del id
		   {
   				if(Almacen[i].codigo == codigoB)
				   {
				   	Almacen[i].existencia -= vendidosLocal;
				   	if(Almacen[i].existencia <= Almacen[i].StockMinimo)
				   		{
				   				Almacen[i].estado = "agotado";
						}
				
					}	
					
					Almacen[i].vendidos = vendidosLocal;
					
			}
			
		}else{
			
			for(i = 0; i<ProductosN; i++)
		 		  {
   			
   					if(Almacen[i].estado == "agotado")
					   {
					   		cout<<"------------------------------\n";
	   						cout <<"Nombre Articulo:"<<Almacen[i].nombre<<endl;
	   						cout <<"Codigo Articulo:"<<Almacen[i].codigo<<endl;
	   						cout <<"Descripcion del Articulo:"<<Almacen[i].descripcion<<endl;
	   						cout <<"Costo Total del Articulo:$"<<Almacen[i].costoT<<endl;
	   						cout <<"Precio por unidad Articulo:$"<<Almacen[i].precioUnidad<<endl;
	   						cout <<"Exitencia Articulo:"<<Almacen[i].existencia<<" Articulos"<<endl;
	   						cout <<"Cantidad de Articulos vendidos:"<<Almacen[i].vendidos<<endl;
	   						cout <<"Estado del Articulo:"<<Almacen[i].estado<<endl;
	   						cout <<"Stock Minimo del Articulo:"<<Almacen[i].StockMinimo<<endl;	
	   						cout <<"\n"; 
   		 			   }
		 		    }
		 		    
		 	}
			
   		 cout <<"¿Quires Salir a Menu Si = s o NO = n?"<<endl;
   		 cin >>respuesta;
   		 
   		 if(respuesta == 's'){
   		 	goto SaltoMenu;
   		 	
		}else if(respuesta == 'n'){
			goto SaltoProceso5;
		}
   		
   	   break;
   	
   	
   	  //Salir del programa. <----------------------------------------------------------------------------Trabajo Javier.
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
