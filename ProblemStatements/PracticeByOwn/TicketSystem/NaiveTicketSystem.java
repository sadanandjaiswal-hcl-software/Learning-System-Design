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

enum TicketType {
    BUG, Incident, Task
}

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

// Service class
class TicketService {

    private Map<Priority, Integer> priorityToSla = new HashMap<>();

    TicketService() {
        priorityToSla.put(Priority.P1, 4);
        priorityToSla.put(Priority.P2, 24);
        priorityToSla.put(Priority.P3, 40);
        priorityToSla.put(Priority.P4, 72);
    }

    public Ticket createTicket(TicketType type, String title, String desc) {
        long id = Ticket.idCounter++;

        if (type == TicketType.BUG) {
            return new BugTicket(
                id, title, desc,
                Priority.P2,
                priorityToSla.get(Priority.P2),
                Status.Started
            );
        } 
        else if (type == TicketType.Incident) {
            return new IncidentTicket(
                id, title, desc,
                Priority.P1,
                priorityToSla.get(Priority.P1),
                Status.Started
            );
        } 
        else if (type == TicketType.Task) {
            return new TaskTicket(
                id, title, desc,
                Priority.P4,
                priorityToSla.get(Priority.P4),
                Status.Started
            );
        }
        return null;
    }
}

// Main class
public class NaiveTicketSystem {
    public static void main(String[] args) throws Exception {

        TicketService service = new TicketService();
        Ticket t1 = service.createTicket(TicketType.BUG, "Login Bug", "Fix login issue");

        System.out.println("Ticket created with ID: " + t1.id);
    }
}


// ************** Problems in this design **************
// 0. TicketService knows TOO MUCH
// 1. Ticket creation logic is tightly coupled within TicketService.
// 2. Adding new ticket types requires modifying TicketService, violating OCP.
// 3. Difficult to manage and extend ticket creation logic.
// 4. No validation or error handling for ticket creation.
// 5. Creation logic is tightly coupled to business logic


// TicketService: Responsible for ticket management (creation, updating, retrieval).
// Ticket Creation Logic: Should be decoupled from TicketService to adhere to OCP.
// Ticket Factory: A separate factory class or method to handle ticket creation based on type. (BugTicket, IncidentTicket, TaskTicket, etc.)