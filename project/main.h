#ifndef _MAIN_H_
#define _MAIN_H_

#define user_space 131072   //80M固态盘空间（64M用户空间+16M过量供应空间)  64M=131072*512B
//#define user_space  2096000   //1.2G固态盘空间
//#define user_space  10066000   //6G  4.8 固态盘空间
//#define user_space  100660000   //60G  48 固态盘空间

//#define user_space  3774800




//80%的trace访问20%的lun空间
#define hot_space 26214
//#define hot_space 26843545
//#define hot_space   754960
//#define hot_space   20132650
#define max_default_rand_num 32767
int get_rand_num(int num);

#endif
