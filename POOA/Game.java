/*
    Tarea #30
*/
import java.util.Random;
public class Game{
    public static void main(String args[]) {
        EnemyFactory enemyFactory1 = new EnemyFactory();
        EnemyFactory enemyFactory2 = new EnemyFactory();
        EnemyFactory enemyFactory3 = new EnemyFactory();
                
        int n=(int) (Math.random()*(4-1)) + 1;                
        enemyFactory1.makeEnemy(n);
        int m=(int) (Math.random()*(4-1)) + 1;   
        enemyFactory2.makeEnemy(m);
        int w=(int) (Math.random()*(4-1)) + 1;
        enemyFactory3.makeEnemy(w);
}
}       
public class EnemyFactory{
    public Enemy makeEnemy(int x){
        if (x==1){
            return new MeleeEnemy();
        }else if (x==2){
            return new MagicEnemy();
        }else if (x==3){
            return new RangedEnemy();
        }else{
            System.out.println("Enemigo no creado");
        }
        return null;
    }
}
public abstract class Enemy{
    private String name;
    private double damage;
    abstract void attackPlayer();
    abstract void setDamage(double y);
    abstract double getDamage();
}
        
public class MeleeEnemy extends Enemy{
    public void setName(String z){
        System.out.println("inside MeleeEnemy::setName() method");
    };
    public String getName(){
        System.out.println("inside MeleeEnemy::getName() method");
    }
   }    
public class MagicEnemy extends Enemy{
    public void setName(String z){
        System.out.println("inside MagicEnemy::setName() method");
    };
    public String getName(){
        System.out.println("inside MagicEnemy::getName() method");
    };
}
public class RangedEnemy extends Enemy{
    public void setName(String z){
        System.out.println("inside RangedEnemy::setName() method");
    };
    public String getName(){
        System.out.println("inside RangedEnemy::getName() method");
    };
}