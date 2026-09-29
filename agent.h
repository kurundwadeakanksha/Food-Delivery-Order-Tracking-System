#ifndef AGENT_H
#define AGENT_H

#define MAX_AGENTS 5

extern char agents[MAX_AGENTS][50];
extern int nextAgent;

void assignAgents();
void ordersByAgent();

#endif