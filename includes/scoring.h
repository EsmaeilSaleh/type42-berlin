#ifndef SCORING_H
#define SCORING_H

int compute_similarity_score(const char *input, const char *expected);
void save_score_log(const char *func_name, int score, const char *mode);

#endif