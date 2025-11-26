import java.util.Scanner;
class An{
	No raiz;
	public void insert(int x){
		inserir(x, raiz, null, null, null);
	}
	public void inserir(int x, No filho, No pai, No avo, No bisavo){
		if(raiz == null){
			raiz = new No(x);
		}else if(pai.dir == null && pai.esq == null){
			if(x > pai.valor){
				pai.dir = new No(x);
			}else if(x < pai.valor){
				pai.esq = new No(x); 
			}	
		}else if(filho.esq == false && filho.dir == false){
			
		}else if(x > filho.valor){
			
		}else if(x < filho.valor){

		}else{

		}
	}
	public void caminha(){
		caminhar(raiz);
	}
	public void caminhar(No i){
		if(i == null){
			return;
		}
		caminhar(i.esq);
		System.out.println(i.valor);
		caminhar(i.dir);
	}
}
class No{
	int valor;
	No dir;
	No esq;
	boolean cor;
	No(int x){
		valor = x;
		cor = false;
		dir = esq = null;
	}
}
public class alvin_negra{
	public static void main(String[] args){

	}
} 
