#ifndef GAME_ROLE_HPP_
#define GAME_ROLE_HPP_

class GameRole
{
private:
   uint32_t  pid;

    /* data */
public:
    GameRole(/* args */){};
    ~GameRole(){};
    uint32_t  getPid(){
        return pid;
    }

    void setPid(uint32_t pid){
        this->pid = pid;
    }

};

#endif