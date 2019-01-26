#include <string>
#include <algorithm>
#include <map>
#include <memory>

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class RegisteredInFactory
{
protected:
    static bool Registered;
};

template <typename T>
bool RegisteredInFactory<T>::Registered = CommandFactory::Register(T::GetStringName(), T::CreateMethod);
////////////////////////////////////////////////////////////////////////////////////////////////////
class CommandFactory
{
public:
    using CreateMethod_t = unique_ptr<Command>(*)();

    CommandFactory() = delete;

    static bool Register(const std::string name, CreateMethod_t funcCreate);
    static unique_ptr<Command> Create(const string& name);

private:
    static std::map<std::string, CreateMethod_t> commands;
};

std::map<std::string, Create_t> CommandFactory::commands;

bool CommandFactory::Register(const std::string name, CreateMethod_t& funcCreate)
{
    if (auto it = commands.find(name); it == commands.end()) {
        commands[name] = funcCreate;
        return true;
    }
    return false;
}

unique_ptr<Command> CommandFactory::Create(const std::string& name)
{
    if (auto it = commands.find(name); it != commands.end()) 
        return it->second();

    return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
class Command
{
public:
    Command() = default;
    virtual ~Command() = default;
    
    template<typename T>
    virtual void execute(T arg) = 0;

private:
    std::string str;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
class UsrCommand : public Command
{};
class StdCommand : public Command
{};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define REGISTER(className, name)                                                   /
public:                                                                             /
    static unique_ptr<Command> CreateMethod() { return make_unique<className>(); }  /
    static std::string GetStringName() { return name; }                             /
private:
//////////////////////////////////////////////////////////////////////////////////////////////////////
class ForwardCommand : public StdCommand, public RegisteredInFactory<ForwardCommand>
{
    REGISTER(ForwardCommand, "FORWARD");
public:
    template<int>
    void execute(int arg) override {
        
        turtle.move()
    }
};

class BackCommand : public StdCommand, public RegisteredInFactory<BackCommand>
{
    REGISTER(BackCommand, "BACK");
public:
    void execute() override {}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void interpet(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    auto pos = str.find(" ")+1;
    std::string strComm = substr(0, pos != std::string::npos ? pos : str.length());
    std::string strArgs = str

    auto comm = getCommand(strComm);
    comm->execute(strArgs);
}

std::unique_ptr<Command> getCommand(std::string str)
{
    return CommandFactory::Create(str);
}

/*
interpet("Forward 100");
interpet("Right 90");
interpet("back 100");
interpet("Left 90");
interpet("FORWARD 100");
*/




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Turtle : darwable
{

    shape     body;
    float     angle;
    vector2   pos;
    bool      penOnBoard;
    color     penColor;

    void move(float offsetX, float offsetY) {
        body.move(offsetX, offsetY);
    }

    void rotate(float angle) {
        body.rotate(angle);
    }

};

class Board : darwable
{
    color backgroudColor;   // window.clear(board.backgroundColor); 
}

class Track : drawable
{
    sf::VertexArray lines(sf::LineStrip, 0);

    void add(vector2 pos) {
        Vertex ver(pos, turtle.penColor);
        lines.appnd(ver);
    }


};



