
    //Backward linking 
    nodeDptr->prevNodePtr = nodeCptr;
    nodeCptr->prevNodePtr = nodeBptr;
    nodeBptr->prevNodePtr = nodeAptr;