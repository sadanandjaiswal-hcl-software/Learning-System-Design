import java.util.*;
import java.lang.*;
import java.io.*;

enum NotificationType{
    EMAIL, SMS, PUSH
}

/*
// Without Strategy Pattern
// Fails : Want to add more service - break open-closed principle
class NotificatoinService{
    public void send(NotificationType type, String message){
        switch(type){
            case NotificationType.EMAIL:
                System.out.println("Email Notification : "+message);
                break;
            case NotificationType.SMS:
                System.out.println("SMS Notification: "+message);
                break;
            case NotificationType.PUSH:
                System.out.println("Push Notification : "+message);
                break;
            default:
                System.out.println("Notification Type Invalid");
        }
    }
}

*/

// ***************************** Strategy Pattern Followed *****************************

interface NotificationSender{
    // no need to mention public, all behaviour in interface are by default public abstract
    void send(String message);
}

class EmailSender implements NotificationSender{
    @Override
    public void send(String message){
        System.out.println("Email Notification : "+message);
    }    
}

class SmsSender implements NotificationSender{
    @Override
    public void send(String message){
        System.out.println("SMS Notification : "+message);
    }    
}

class PushSender implements NotificationSender{
    @Override
    public void send(String message){
        System.out.println("Push Notification : "+message);
    }    
}

class NotificatoinService{
    private NotificationSender sender;
    
    NotificatoinService(NotificationSender sender){
        this.sender = sender;
    }
    
    public void send(String message){
        sender.send(message);
    }
}

class StrategyPattern
{
	public static void main (String[] args) throws java.lang.Exception
	{
        NotificatoinService emailService = new NotificatoinService(new EmailSender());
        NotificatoinService smsService = new NotificatoinService(new SmsSender());
        NotificatoinService pushService = new NotificatoinService(new PushSender());
        
        emailService.send("Hello Email!");
        smsService.send("Hello SMS!");
        pushService.send("Hello Push!");
	}
}
