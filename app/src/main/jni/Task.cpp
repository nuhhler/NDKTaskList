#include <Task.h>

Task::Task( int theId, const std::string& theName, bool theIsDone ) :
                      id(theId), name(theName), is_done(theIsDone) {}

const std::string& Task::getName() const
{
    return name;
}

void Task::setName( const std::string& theName )
{
    name = theName;
}

bool Task::isDone() const
{
    return is_done;
}


void Task::setIsDone( bool theIsDone )
{
    is_done = theIsDone;
}

int Task::getId() const
{
    return id;
}
