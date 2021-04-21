/*
    Tarea #31
*/
import java.io.ObjectInputStream;
import java.util.Scanner;

public class Pizza{
    public static void main(String args[]) {
        PizzaFactory pizzaFactory=new PizzaFactory();
        Scanner leer=new Scanner(System.in);
        System.out.println("Que Pizza desea ordenar? ");
        String opcion=leer.nextLine();
        pizzaFactory.makePizza(opcion);
    }
}
public class PizzaFactory{
    public Pizza makePizza(String a){
        if (a.equalsIgnoreCase("peperoni")){
            return new PepperoniPizza();
        }else if(a.equalsIgnoreCase("chesse")){
            return new ChessePizza();
        }else if(a.equalsIgnoreCase("hawaiian")){
            return new HawaiianPizza();
        }else if(a.equalsIgnoreCase("veggie")){
            return new VeggiePizza();
        }else{
            System.out.println("No tenemos ese tipo de pizza");
        }
        return null;
    }       
}
public abstract class Pizza{
    public String name;
    public abstract void prepare();
    public abstract void bake();
    public abstract void cut();
    public abstract void box();
    public abstract String getName();
}
public class PepperoniPizza extends Pizza{
    /*
    */
}
public class ChessePizza extends Pizza{
    /*
    */
}
public class HawaiianPizza extends Pizza{
    /*
    */
}
public class VeggiePizza extends Pizza{
    /*
    */
}

