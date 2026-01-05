package ProblemStatements.PracticeByOwn.TicketSystem;
import java.util.*;

// Enums
enum Priority {
    P1, P2, P3, P4
}

enum Status {
    Pending, Started, Paused, Closed
}

// =====================
// Product Interfaces / Base Classes
// =====================
class Ticket {
    protected static long idCounter = 1;

    protected long id;
    protected String title;
    protected String description;
    protected Priority priority;
    protected Status status;

    Ticket(String title, String description, Priority priority, Status status) {
        this.id = idCounter++;
        this.title = title;
        this.description = description;
        this.priority = priority;
        this.status = status;
    }

    public void showTicket() {
        System.out.println("Ticket ID: " + id + ", Title: " + title + ", Status: " + status + ", Priority: " + priority);
    }
}

// Workflow interface
interface Workflow {
    void start();
    void pause();
    void close();
}

// =====================
// Concrete Products – BUG
// =====================
class BugTicket extends Ticket {
    BugTicket(String title, String description) {
        super(title, description, Priority.P1, Status.Started);
    }
}

class BugWorkflow implements Workflow {
    @Override
    public void start() { System.out.println("Bug workflow started"); }
    @Override
    public void pause() { System.out.println("Bug workflow paused"); }
    @Override
    public void close() { System.out.println("Bug workflow closed"); }
}

// =====================
// Concrete Products – INCIDENT
// =====================
class IncidentTicket extends Ticket {
    IncidentTicket(String title, String description) {
        super(title, description, Priority.P2, Status.Started);
    }
}

class IncidentWorkflow implements Workflow {
    @Override
    public void start() { System.out.println("Incident workflow started"); }
    @Override
    public void pause() { System.out.println("Incident workflow paused"); }
    @Override
    public void close() { System.out.println("Incident workflow closed"); }
}

// =====================
// Concrete Products – TASK
// =====================
class TaskTicket extends Ticket {
    TaskTicket(String title, String description) {
        super(title, description, Priority.P3, Status.Started);
    }
}

class TaskWorkflow implements Workflow {
    @Override
    public void start() { System.out.println("Task workflow started"); }
    @Override
    public void pause() { System.out.println("Task workflow paused"); }
    @Override
    public void close() { System.out.println("Task workflow closed"); }
}

// =====================
// Abstract Factory
// =====================
interface TicketSystemFactory {
    Ticket createTicket(String title, String description);
    Workflow createWorkflow();
}

// =====================
// Concrete Factories
// =====================
class BugTicketSystemFactory implements TicketSystemFactory {
    @Override
    public Ticket createTicket(String title, String description) {
        return new BugTicket(title, description);
    }

    @Override
    public Workflow createWorkflow() {
        return new BugWorkflow();
    }
}

class IncidentTicketSystemFactory implements TicketSystemFactory {
    @Override
    public Ticket createTicket(String title, String description) {
        return new IncidentTicket(title, description);
    }

    @Override
    public Workflow createWorkflow() {
        return new IncidentWorkflow();
    }
}

class TaskTicketSystemFactory implements TicketSystemFactory {
    @Override
    public Ticket createTicket(String title, String description) {
        return new TaskTicket(title, description);
    }

    @Override
    public Workflow createWorkflow() {
        return new TaskWorkflow();
    }
}

// =====================
// Service Layer
// =====================
class TicketService {
    private TicketSystemFactory factory;

    TicketService(TicketSystemFactory factory) {
        this.factory = factory;
    }

    public Ticket createTicket(String title, String description) {
        return factory.createTicket(title, description);
    }

    public Workflow createWorkflow() {
        return factory.createWorkflow();
    }
}

// =====================
// Main / Demo
// =====================
public class AbstractTicketSystem {
    public static void main(String[] args) {

        // Using Bug Factory
        TicketService bugService = new TicketService(new BugTicketSystemFactory());
        Ticket bugTicket = bugService.createTicket("Login Bug", "Fix login issue");
        Workflow bugWorkflow = bugService.createWorkflow();

        bugTicket.showTicket();
        bugWorkflow.start();
        bugWorkflow.pause();
        bugWorkflow.close();

        System.out.println();

        // Using Incident Factory
        TicketService incidentService = new TicketService(new IncidentTicketSystemFactory());
        Ticket incidentTicket = incidentService.createTicket("Server Down", "Production server down");
        Workflow incidentWorkflow = incidentService.createWorkflow();

        incidentTicket.showTicket();
        incidentWorkflow.start();
        incidentWorkflow.close();
    }
}
