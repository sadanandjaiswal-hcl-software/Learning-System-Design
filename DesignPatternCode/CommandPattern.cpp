#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

/* =======================
   Command Interface
   ======================= */
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

/* =======================
   Receivers
   ======================= */
class AC {
public:
    void on()        { cout << "AC ON\n"; }
    void off()       { cout << "AC OFF\n"; }
    void tempUp()    { cout << "AC Temperature Increased\n"; }
    void tempDown()  { cout << "AC Temperature Decreased\n"; }
};

class Fan {
    int speed = 0;
public:
    void on() {
        speed = 1;
        cout << "Fan ON (speed 1)\n";
    }
    void off() {
        speed = 0;
        cout << "Fan OFF\n";
    }
    void speedUp() {
        if (speed < 5) speed++;
        cout << "Fan Speed: " << speed << "\n";
    }
    void speedDown() {
        if (speed > 0) speed--;
        cout << "Fan Speed: " << speed << "\n";
    }
};

/* =======================
   Concrete Commands
   ======================= */

// AC Power
class ACOnCommand : public Command {
    AC* ac;
public:
    ACOnCommand(AC* ac) : ac(ac) {}
    void execute() override { ac->on(); }
    void undo() override    { ac->off(); }
};

// AC Temperature
class ACTempUpCommand : public Command {
    AC* ac;
public:
    ACTempUpCommand(AC* ac) : ac(ac) {}
    void execute() override { ac->tempUp(); }
    void undo() override    { ac->tempDown(); }
};

// Fan Power
class FanOnCommand : public Command {
    Fan* fan;
public:
    FanOnCommand(Fan* fan) : fan(fan) {}
    void execute() override { fan->on(); }
    void undo() override    { fan->off(); }
};

// Fan Speed
class FanSpeedUpCommand : public Command {
    Fan* fan;
public:
    FanSpeedUpCommand(Fan* fan) : fan(fan) {}
    void execute() override { fan->speedUp(); }
    void undo() override    { fan->speedDown(); }
};

/* =======================
   Macro Command
   ======================= */
class MacroCommand : public Command {
    vector<Command*> commands;
public:
    MacroCommand(const vector<Command*>& cmds) : commands(cmds) {}

    void execute() override {
        cout << "--- Macro Execute ---\n";
        for (auto cmd : commands)
            cmd->execute();
    }

    void undo() override {
        cout << "--- Macro Undo ---\n";
        for (auto it = commands.rbegin(); it != commands.rend(); ++it)
            (*it)->undo();
    }
};

/* =======================
   Invoker (Remote)
   ======================= */
class RemoteController {
    vector<unique_ptr<Command>> buttons;
    stack<Command*> history;

public:
    RemoteController(int size) : buttons(size) {}

    void setCommand(int index, unique_ptr<Command> cmd) {
        if (index >= 0 && index < buttons.size())
            buttons[index] = move(cmd);
    }

    void pressButton(int index) {
        if (index >= 0 && index < buttons.size() && buttons[index]) {
            buttons[index]->execute();
            history.push(buttons[index].get());
        }
    }

    void undo() {
        if (!history.empty()) {
            history.top()->undo();
            history.pop();
        }
    }
};

/* =======================
   Client
   ======================= */
int main() {
    AC ac;
    Fan fan;

    RemoteController remote(5);

    auto acOn       = make_unique<ACOnCommand>(&ac);
    auto acTempUp   = make_unique<ACTempUpCommand>(&ac);
    auto fanOn      = make_unique<FanOnCommand>(&fan);
    auto fanSpeedUp = make_unique<FanSpeedUpCommand>(&fan);

    vector<Command*> movieMode {
        acOn.get(),
        acTempUp.get(),
        fanOn.get(),
        fanSpeedUp.get()
    };

    auto macro = make_unique<MacroCommand>(movieMode);

    remote.setCommand(0, move(acOn));
    remote.setCommand(1, move(acTempUp));
    remote.setCommand(2, move(fanOn));
    remote.setCommand(3, move(fanSpeedUp));
    remote.setCommand(4, move(macro));

    cout << "\n--- Movie Mode Button ---\n";
    remote.pressButton(4);

    cout << "\n--- Undo Operations ---\n";
    remote.undo();
    remote.undo();
    remote.undo();

    return 0;
}
