package DesignPatternCode;

import java.util.*;
import java.lang.*;
import java.io.*;

interface NotificationChannel {
    void notify(String message);
}

class EmailChannel implements NotificationChannel {
    private String from;
    private String to;
    private String subject;
    
    public EmailChannel(String from, String to, String subject){
        this.from = from ;
        this.to = to;
        this.subject = subject;
    }
    
    @Override
    public void notify(String message) {
        System.out.println("Sending email...");
        System.out.println("From : "+from);
        System.out.println("To : "+to);
        System.out.println("Subject : "+subject);
        System.out.println("Body : "+message);
    }
}

class SMSChannel implements NotificationChannel {
    @Override
    public void notify(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

class PushChannel implements NotificationChannel {
    @Override
    public void notify(String message) {
        System.out.println("Sending push notification: " + message);
    }
}

// component
interface Notification{
    public void send();
}

// concreteComponent
class BaseNotification implements Notification{
    private String msg;
    private NotificationChannel channel;
    public BaseNotification(String msg, NotificationChannel channel){
        this.msg = msg;
        this.channel = channel;
    }
    
    @Override
    public void send(){
        System.out.println("Messgae: "+msg);
        channel.notify(msg);
    }
}

// decorator
abstract class NotificationDecorator implements Notification{
    protected Notification notification;
    public NotificationDecorator(Notification notification){
        this.notification = notification;
    }
}

// concreteDecorator
class LoggingDecorator extends NotificationDecorator{
    public LoggingDecorator(Notification notification){
        super(notification);
    }
    
    @Override
    public void send(){
        System.out.println("Logging notification.");
        notification.send();
    }
}

class RetryDecorator extends NotificationDecorator{
    public RetryDecorator(Notification notification){
        super(notification);
    }
    
    @Override
    public void send(){
        System.out.println("Retrying...");
        notification.send();
    }
}

class EncryptedDecorator extends NotificationDecorator{
    public EncryptedDecorator(Notification notification){
        super(notification);
    }
    
    @Override
    public void send(){
        System.out.println("Encryption Done.");
        notification.send();
    }
}

class RateLimitDecorator extends NotificationDecorator{
    public RateLimitDecorator(Notification notification){
        super(notification);
    }
    
    @Override
    public void send(){
        System.out.println("Rate limiting applied.");
        notification.send();
    }
}

class DecoratorPlusStrategy {
    public static void main (String[] args) throws java.lang.Exception
	{
        NotificationChannel emailChannel = new EmailChannel("senderUser123@gmail.com","receiverUser321@gmail.com","My Love for You");
        String message = "Hello Darling, \nHow are you? I'm planning for trip to Manali with you this month, are you excited?";
        Notification notification = new LoggingDecorator(
            new EncryptedDecorator(
                new RateLimitDecorator(
                    new BaseNotification(message, emailChannel)
                )
            )
        );
        
        notification.send();
	}
}
