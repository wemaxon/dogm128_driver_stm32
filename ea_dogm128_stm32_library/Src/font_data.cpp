#include "font_data.hpp"

const Font smallFT = {6, 5, 4,
		{0xFF, 0xFF, 0xFF, 0xFF,  // ASCI 0
		0x00, 0x00, 0x00, 0x00,  // ASCI 1
		0x00, 0x00, 0x00, 0x00,  // ASCI 2
		0x00, 0x00, 0x00, 0x00,  // ASCI 3
		0x00, 0x00, 0x00, 0x00,  // ASCI 4
		0x00, 0x00, 0x00, 0x00,  // ASCI 5
		0x00, 0x00, 0x00, 0x00,  // ASCI 6
		0x00, 0x00, 0x00, 0x00,  // ASCI 7
		0x00, 0x00, 0x00, 0x00,  // ASCI 8
		0x00, 0x00, 0x00, 0x00,  // ASCI 9
		0x00, 0x00, 0x00, 0x00,  // ASCI 10
		0x00, 0x00, 0x00, 0x00,  // ASCI 11
		0x00, 0x00, 0x00, 0x00,  // ASCI 12
		0x00, 0x00, 0x00, 0x00,  // ASCI 13
		0x00, 0x00, 0x00, 0x00,  // ASCI 14
		0x00, 0x00, 0x00, 0x00,  // ASCI 15
		0x00, 0x00, 0x00, 0x00,  // ASCI 16
		0x00, 0x00, 0x00, 0x00,  // ASCI 17
		0x00, 0x00, 0x00, 0x00,  // ASCI 18
		0x00, 0x00, 0x00, 0x00,  // ASCI 19
		0x00, 0x00, 0x00, 0x00,  // ASCI 20
		0x00, 0x00, 0x00, 0x00,  // ASCI 21
		0x00, 0x00, 0x00, 0x00,  // ASCI 22
		0x00, 0x00, 0x00, 0x00,  // ASCI 23
		0x00, 0x00, 0x00, 0x00,  // ASCI 24
		0x00, 0x00, 0x00, 0x00,  // ASCI 25
		0x00, 0x00, 0x00, 0x00,  // ASCI 26
		0x00, 0x00, 0x00, 0x00,  // ASCI 27
		0x00, 0x00, 0x00, 0x00,  // ASCI 28
		0x00, 0x00, 0x00, 0x00,  // ASCI 29
		0x00, 0x00, 0x00, 0x00,  // ASCI 30
		0x00, 0x00, 0x00, 0x00,  // ASCI 31
		0x00, 0x00, 0x00, 0x00,  // ASCI 32
		0x00, 0x00, 0x00, 0x00,  // ASCI 33
		0x00, 0x00, 0x00, 0x00,  // ASCI 34
		0x00, 0x00, 0x00, 0x00,  // ASCI 35
		0x00, 0x00, 0x00, 0x00,  // ASCI 36
		0x00, 0x00, 0x00, 0x00,  // ASCI 37
		0x00, 0x00, 0x00, 0x00,  // ASCI 38
		0x00, 0x00, 0x00, 0x00,  // ASCI 39
		0x00, 0x00, 0x00, 0x00,  // ASCI 40
		0x00, 0x00, 0x00, 0x00,  // ASCI 41
		0x00, 0x00, 0x00, 0x00,  // ASCI 42
		0x00, 0x00, 0x00, 0x00,  // ASCI 43
		0x00, 0x00, 0x00, 0x00,  // ASCI 44
		0x00, 0x00, 0x00, 0x00,  // ASCI 45
		0x00, 0x00, 0x00, 0x00,  // ASCI 46
		0x00, 0x00, 0x00, 0x00,  // ASCI 47
		0x00, 0x00, 0x00, 0x00,  // ASCI 48
		0x00, 0x00, 0x00, 0x00,  // ASCI 49
		0x00, 0x00, 0x00, 0x00,  // ASCI 50
		0x00, 0x00, 0x00, 0x00,  // ASCI 51
		0x00, 0x00, 0x00, 0x00,  // ASCI 52
		0x00, 0x00, 0x00, 0x00,  // ASCI 53
		0x00, 0x00, 0x00, 0x00,  // ASCI 54
		0x00, 0x00, 0x00, 0x00,  // ASCI 55
		0x00, 0x00, 0x00, 0x00,  // ASCI 56
		0x00, 0x00, 0x00, 0x00,  // ASCI 57
		0x00, 0x00, 0x00, 0x00,  // ASCI 58
		0x00, 0x00, 0x00, 0x00,  // ASCI 59
		0x00, 0x00, 0x00, 0x00,  // ASCI 60
		0x00, 0x00, 0x00, 0x00,  // ASCI 61
		0x00, 0x00, 0x00, 0x00,  // ASCI 62
		0x00, 0x00, 0x00, 0x00,  // ASCI 63
		0x00, 0x00, 0x00, 0x00,  // ASCI 64
		0xFA, 0x2F, 0xA2, 0x88,  // ASCI 65
		0xF2, 0x2F, 0xA2, 0xF0,  // ASCI 66
		0xF2, 0x08, 0x20, 0xF0,  // ASCI 67
		0xE2, 0x49, 0x24, 0xE0,  // ASCI 68
		0xF2, 0x0F, 0x20, 0xF0,  // ASCI 69
		0xF2, 0x0E, 0x20, 0x80,  // ASCI 70
		0xF2, 0x0B, 0x24, 0xF0,  // ASCI 71
		0x92, 0x4F, 0x24, 0x90,  // ASCI 72
		0x70, 0x82, 0x08, 0x70,  // ASCI 73
		0xF0, 0x82, 0x28, 0xE0,  // ASCI 74
		0x92, 0x8C, 0x28, 0x90,  // ASCI 75
		0x82, 0x08, 0x20, 0xF0,  // ASCI 76
		0x8B, 0x6A, 0xA2, 0x88,  // ASCI 77
		0x8B, 0x2A, 0xA6, 0x88,  // ASCI 78
		0x72, 0x28, 0xA2, 0x70,  // ASCI 79
		0xF2, 0x4F, 0x20, 0x80,  // ASCI 80
		0x62, 0x49, 0x24, 0x78,  // ASCI 81
		0xF2, 0x4F, 0x28, 0x90,  // ASCI 82
		0x72, 0x06, 0x04, 0xE0,  // ASCI 83
		0xF8, 0x82, 0x08, 0x20,  // ASCI 84
		0x92, 0x49, 0x24, 0xF0,  // ASCI 85
		0x8A, 0x28, 0x94, 0x20,  // ASCI 86
		0xAA, 0xAA, 0xAA, 0x50,  // ASCI 87
		0x89, 0x42, 0x14, 0x88,  // ASCI 88
		0x89, 0x42, 0x08, 0x20,  // ASCI 89
		0xF8, 0x42, 0x10, 0xF8,  // ASCI 90
		0x00, 0x00, 0x00, 0x00,  // ASCI 91
		0x00, 0x00, 0x00, 0x00,  // ASCI 92
		0x00, 0x00, 0x00, 0x00,  // ASCI 93
		0x00, 0x00, 0x00, 0x00,  // ASCI 94
		0x00, 0x00, 0x00, 0x00,  // ASCI 95
		0x00, 0x00, 0x00, 0x00,  // ASCI 96
		0x00, 0x00, 0x00, 0x00,  // ASCI 97
		0x00, 0x00, 0x00, 0x00,  // ASCI 98
		0x00, 0x00, 0x00, 0x00,  // ASCI 99
		0x00, 0x00, 0x00, 0x00,  // ASCI 100
		0x00, 0x00, 0x00, 0x00,  // ASCI 101
		0x00, 0x00, 0x00, 0x00,  // ASCI 102
		0x00, 0x00, 0x00, 0x00,  // ASCI 103
		0x00, 0x00, 0x00, 0x00,  // ASCI 104
		0x00, 0x00, 0x00, 0x00,  // ASCI 105
		0x00, 0x00, 0x00, 0x00,  // ASCI 106
		0x00, 0x00, 0x00, 0x00,  // ASCI 107
		0x00, 0x00, 0x00, 0x00,  // ASCI 108
		0x00, 0x00, 0x00, 0x00,  // ASCI 109
		0x00, 0x00, 0x00, 0x00,  // ASCI 110
		0x00, 0x00, 0x00, 0x00,  // ASCI 111
		0x00, 0x00, 0x00, 0x00,  // ASCI 112
		0x00, 0x00, 0x00, 0x00,  // ASCI 113
		0x00, 0x00, 0x00, 0x00,  // ASCI 114
		0x00, 0x00, 0x00, 0x00,  // ASCI 115
		0x00, 0x00, 0x00, 0x00,  // ASCI 116
		0x00, 0x00, 0x00, 0x00,  // ASCI 117
		0x00, 0x00, 0x00, 0x00,  // ASCI 118
		0x00, 0x00, 0x00, 0x00,  // ASCI 119
		0x00, 0x00, 0x00, 0x00,  // ASCI 120
		0x00, 0x00, 0x00, 0x00,  // ASCI 121
		0x00, 0x00, 0x00, 0x00,  // ASCI 122
		0x00, 0x00, 0x00, 0x00,  // ASCI 123
		0x00, 0x00, 0x00, 0x00,  // ASCI 124
		0x00, 0x00, 0x00, 0x00,  // ASCI 125
		0x00, 0x00, 0x00, 0x00,  // ASCI 126
		0x00, 0x00, 0x00, 0x00,  // ASCI 127
		0x00, 0x00, 0x00, 0x00,  // ASCI 128
		0x00, 0x00, 0x00, 0x00,  // ASCI 129
		0x00, 0x00, 0x00, 0x00,  // ASCI 130
		0x00, 0x00, 0x00, 0x00,  // ASCI 131
		0x00, 0x00, 0x00, 0x00,  // ASCI 132
		0x00, 0x00, 0x00, 0x00,  // ASCI 133
		0x00, 0x00, 0x00, 0x00,  // ASCI 134
		0x00, 0x00, 0x00, 0x00,  // ASCI 135
		0x00, 0x00, 0x00, 0x00,  // ASCI 136
		0x00, 0x00, 0x00, 0x00,  // ASCI 137
		0x00, 0x00, 0x00, 0x00,  // ASCI 138
		0x00, 0x00, 0x00, 0x00,  // ASCI 139
		0x00, 0x00, 0x00, 0x00,  // ASCI 140
		0x00, 0x00, 0x00, 0x00,  // ASCI 141
		0x00, 0x00, 0x00, 0x00,  // ASCI 142
		0x00, 0x00, 0x00, 0x00,  // ASCI 143
		0x00, 0x00, 0x00, 0x00,  // ASCI 144
		0x00, 0x00, 0x00, 0x00,  // ASCI 145
		0x00, 0x00, 0x00, 0x00,  // ASCI 146
		0x00, 0x00, 0x00, 0x00,  // ASCI 147
		0x00, 0x00, 0x00, 0x00,  // ASCI 148
		0x00, 0x00, 0x00, 0x00,  // ASCI 149
		0x00, 0x00, 0x00, 0x00,  // ASCI 150
		0x00, 0x00, 0x00, 0x00,  // ASCI 151
		0x00, 0x00, 0x00, 0x00,  // ASCI 152
		0x00, 0x00, 0x00, 0x00,  // ASCI 153
		0x00, 0x00, 0x00, 0x00,  // ASCI 154
		0x00, 0x00, 0x00, 0x00,  // ASCI 155
		0x00, 0x00, 0x00, 0x00,  // ASCI 156
		0x00, 0x00, 0x00, 0x00,  // ASCI 157
		0x00, 0x00, 0x00, 0x00,  // ASCI 158
		0x00, 0x00, 0x00, 0x00,  // ASCI 159
		0x00, 0x00, 0x00, 0x00,  // ASCI 160
		0x00, 0x00, 0x00, 0x00,  // ASCI 161
		0x00, 0x00, 0x00, 0x00,  // ASCI 162
		0x00, 0x00, 0x00, 0x00,  // ASCI 163
		0x00, 0x00, 0x00, 0x00,  // ASCI 164
		0x00, 0x00, 0x00, 0x00,  // ASCI 165
		0x00, 0x00, 0x00, 0x00,  // ASCI 166
		0x00, 0x00, 0x00, 0x00,  // ASCI 167
		0x00, 0x00, 0x00, 0x00,  // ASCI 168
		0x00, 0x00, 0x00, 0x00,  // ASCI 169
		0x00, 0x00, 0x00, 0x00,  // ASCI 170
		0x00, 0x00, 0x00, 0x00,  // ASCI 171
		0x00, 0x00, 0x00, 0x00,  // ASCI 172
		0x00, 0x00, 0x00, 0x00,  // ASCI 173
		0x00, 0x00, 0x00, 0x00,  // ASCI 174
		0x00, 0x00, 0x00, 0x00,  // ASCI 175
		0x00, 0x00, 0x00, 0x00,  // ASCI 176
		0x00, 0x00, 0x00, 0x00,  // ASCI 177
		0x00, 0x00, 0x00, 0x00,  // ASCI 178
		0x00, 0x00, 0x00, 0x00,  // ASCI 179
		0x00, 0x00, 0x00, 0x00,  // ASCI 180
		0x00, 0x00, 0x00, 0x00,  // ASCI 181
		0x00, 0x00, 0x00, 0x00,  // ASCI 182
		0x00, 0x00, 0x00, 0x00,  // ASCI 183
		0x00, 0x00, 0x00, 0x00,  // ASCI 184
		0x00, 0x00, 0x00, 0x00,  // ASCI 185
		0x00, 0x00, 0x00, 0x00,  // ASCI 186
		0x00, 0x00, 0x00, 0x00,  // ASCI 187
		0x00, 0x00, 0x00, 0x00,  // ASCI 188
		0x00, 0x00, 0x00, 0x00,  // ASCI 189
		0x00, 0x00, 0x00, 0x00,  // ASCI 190
		0x00, 0x00, 0x00, 0x00,  // ASCI 191
		0x00, 0x00, 0x00, 0x00,  // ASCI 192
		0x00, 0x00, 0x00, 0x00,  // ASCI 193
		0x00, 0x00, 0x00, 0x00,  // ASCI 194
		0x00, 0x00, 0x00, 0x00,  // ASCI 195
		0x00, 0x00, 0x00, 0x00,  // ASCI 196
		0x00, 0x00, 0x00, 0x00,  // ASCI 197
		0x00, 0x00, 0x00, 0x00,  // ASCI 198
		0x00, 0x00, 0x00, 0x00,  // ASCI 199
		0x00, 0x00, 0x00, 0x00,  // ASCI 200
		0x00, 0x00, 0x00, 0x00,  // ASCI 201
		0x00, 0x00, 0x00, 0x00,  // ASCI 202
		0x00, 0x00, 0x00, 0x00,  // ASCI 203
		0x00, 0x00, 0x00, 0x00,  // ASCI 204
		0x00, 0x00, 0x00, 0x00,  // ASCI 205
		0x00, 0x00, 0x00, 0x00,  // ASCI 206
		0x00, 0x00, 0x00, 0x00,  // ASCI 207
		0x00, 0x00, 0x00, 0x00,  // ASCI 208
		0x00, 0x00, 0x00, 0x00,  // ASCI 209
		0x00, 0x00, 0x00, 0x00,  // ASCI 210
		0x00, 0x00, 0x00, 0x00,  // ASCI 211
		0x00, 0x00, 0x00, 0x00,  // ASCI 212
		0x00, 0x00, 0x00, 0x00,  // ASCI 213
		0x00, 0x00, 0x00, 0x00,  // ASCI 214
		0x00, 0x00, 0x00, 0x00,  // ASCI 215
		0x00, 0x00, 0x00, 0x00,  // ASCI 216
		0x00, 0x00, 0x00, 0x00,  // ASCI 217
		0x00, 0x00, 0x00, 0x00,  // ASCI 218
		0x00, 0x00, 0x00, 0x00,  // ASCI 219
		0x00, 0x00, 0x00, 0x00,  // ASCI 220
		0x00, 0x00, 0x00, 0x00,  // ASCI 221
		0x00, 0x00, 0x00, 0x00,  // ASCI 222
		0x00, 0x00, 0x00, 0x00,  // ASCI 223
		0x00, 0x00, 0x00, 0x00,  // ASCI 224
		0x00, 0x00, 0x00, 0x00,  // ASCI 225
		0x00, 0x00, 0x00, 0x00,  // ASCI 226
		0x00, 0x00, 0x00, 0x00,  // ASCI 227
		0x00, 0x00, 0x00, 0x00,  // ASCI 228
		0x00, 0x00, 0x00, 0x00,  // ASCI 229
		0x00, 0x00, 0x00, 0x00,  // ASCI 230
		0x00, 0x00, 0x00, 0x00,  // ASCI 231
		0x00, 0x00, 0x00, 0x00,  // ASCI 232
		0x00, 0x00, 0x00, 0x00,  // ASCI 233
		0x00, 0x00, 0x00, 0x00,  // ASCI 234
		0x00, 0x00, 0x00, 0x00,  // ASCI 235
		0x00, 0x00, 0x00, 0x00,  // ASCI 236
		0x00, 0x00, 0x00, 0x00,  // ASCI 237
		0x00, 0x00, 0x00, 0x00,  // ASCI 238
		0x00, 0x00, 0x00, 0x00,  // ASCI 239
		0x00, 0x00, 0x00, 0x00,  // ASCI 240
		0x00, 0x00, 0x00, 0x00,  // ASCI 241
		0x00, 0x00, 0x00, 0x00,  // ASCI 242
		0x00, 0x00, 0x00, 0x00,  // ASCI 243
		0x00, 0x00, 0x00, 0x00,  // ASCI 244
		0x00, 0x00, 0x00, 0x00,  // ASCI 245
		0x00, 0x00, 0x00, 0x00,  // ASCI 246
		0x00, 0x00, 0x00, 0x00,  // ASCI 247
		0x00, 0x00, 0x00, 0x00,  // ASCI 248
		0x00, 0x00, 0x00, 0x00,  // ASCI 249
		0x00, 0x00, 0x00, 0x00,  // ASCI 250
		0x00, 0x00, 0x00, 0x00,  // ASCI 251
		0x00, 0x00, 0x00, 0x00,  // ASCI 252
		0x00, 0x00, 0x00, 0x00,  // ASCI 253
		0x00, 0x00, 0x00, 0x00,  // ASCI 254
		0x00, 0x00, 0x00, 0x00 // ASCI 255
		}};
