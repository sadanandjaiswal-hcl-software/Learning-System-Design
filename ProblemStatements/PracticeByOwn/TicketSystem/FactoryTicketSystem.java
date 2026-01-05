package ProblemStatements.PracticeByOwn.TicketSystem;

import java.util.*;
import java.lang.*;
import java.io.*;

// Enums
enum Priority {
    P1, P2, P3, P4
}

enum Status {
    Pending, Closed, Started, Paused
}

/*
    No need of this, factory method eliminate its use
    
    enum TicketType {
        BUG, Incident, Task
    }
*/

// Base Ticket class
class Ticket {
    protected static long idCounter = 1;

    protected long id;
    protected String title;
    protected String description;
    protected Priority priority;
    protected int slaHours;
    protected Status status;

    Ticket(long id, String title, String description,
           Priority priority, int slaHours, Status status) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.priority = priority;
        this.slaHours = slaHours;
        this.status = status;
    }

    // Getters / setters can be added here
}

// Subclasses
class BugTicket extends Ticket {
    BugTicket(long id, String title, String description,
              Priority priority, int slaHours, Status status) {
        super(id, title, description, priority, slaHours, status);
    }
}

class IncidentTicket extends Ticket {
    IncidentTicket(long id, String title, String description,
                   Priority priority, int slaHours, Status status) {
        super(id, title, description, priority, slaHours, status);
    }
}

class TaskTicket extends Ticket {
    TaskTicket(long id, String title, String description,
               Priority priority, int slaHours, Status status) {
        super(id, title, description, priority, slaHours, status);
    }
}

// ************** Factory and ConcreteFactories  ************** //

/*
    Here I have used : interface
    Think Ahead: If concreteFactories want to share command logics like ID generation, Validation
    Thats why use : Abstract class
    
    abstract class TicketFactory{}
*/
interface TicketFactory{
    public Ticket create(String title, String description);// = 0;
}

class BugTicketFactory implements TicketFactory{
    @Override
    public Ticket create(String title, String description){
        // Acceptable for now, but not ideal in real system
        // Later : id generation move to DB, Repository, Service
        long id = Ticket.idCounter++;
        
        return new BugTicket(id, title, description, Priority.P2, 36, Status.Started);
    }
}

class IncidentTicketFactory implements TicketFactory{
    @Override
    public Ticket create(String title, String description){
        long id = Ticket.idCounter++;
        return new IncidentTicket(id, title, description, Priority.P1, 4, Status.Started);
    }
}

class TaskTicketFactory implements TicketFactory{
    @Override
    public Ticket create(String title, String description){
        long id = Ticket.idCounter++;
        return new TaskTicket(id, title, description, Priority.P4, 72, Status.Started);
    }
}

// Service class
class TicketService {
    private TicketFactory ticketFactory;
    
    TicketService(TicketFactory factory){
        this.ticketFactory = factory;
    }

    public Ticket createTicket(String title, String description) {
        return ticketFactory.create(title, description);
    }
}

// Main class
class FactoryTicketSystem {
    public static void main(String[] args) throws Exception {

        TicketService service = new TicketService(new BugTicketFactory());
        Ticket t1 = service.createTicket("Login Bug", "Fix login issue");

        System.out.println("Ticket created with ID: " + t1.id);
    }
}



// Improvement Needed --> Moving to Abstract Factory Pattern

// 1. Factory create only Ticket, what if we want to also create SLA Policy, Priority Policy etc