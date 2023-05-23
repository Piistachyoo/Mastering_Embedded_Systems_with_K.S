
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <Uart_Send_String>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e492d6e 	cdpvs	13, 4, cr2, cr9, cr14, {3}
   8:	7065442d 	rsbvc	r4, r5, sp, lsr #8
   c:	203a6874 	eorscs	r6, sl, r4, ror r8
  10:	72616d4f 	rsbvc	r6, r1, #5056	; 0x13c0
  14:	6d615920 			; <UNDEFINED> instruction: 0x6d615920
  18:	00796e61 	rsbseq	r6, r9, r1, ror #28
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000af 	andeq	r0, r0, pc, lsr #1
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000009d 	muleq	r0, sp, r0
  10:	00000e0c 	andeq	r0, r0, ip, lsl #28
  14:	00004300 	andeq	r4, r0, r0, lsl #6
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001c00 	andeq	r1, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	08010200 	stmdaeq	r1, {r9}
  28:	000000fa 	strdeq	r0, [r0], -sl
  2c:	3e060102 	adfccs	f0, f6, f2
  30:	03000001 	movweq	r0, #1
  34:	00000014 	andeq	r0, r0, r4, lsl r0
  38:	25181d02 	ldrcs	r1, [r8, #-3330]	; 0xfffff2fe
  3c:	02000000 	andeq	r0, r0, #0
  40:	01500502 	cmpeq	r0, r2, lsl #10
  44:	02020000 	andeq	r0, r2, #0
  48:	00012b07 	andeq	r2, r1, r7, lsl #22
  4c:	05040200 	streq	r0, [r4, #-512]	; 0xfffffe00
  50:	0000010d 	andeq	r0, r0, sp, lsl #2
  54:	00050802 	andeq	r0, r5, r2, lsl #16
  58:	02000000 	andeq	r0, r0, #0
  5c:	001a0704 	andseq	r0, sl, r4, lsl #14
  60:	08020000 	stmdaeq	r2, {}	; <UNPREDICTABLE>
  64:	00002c07 	andeq	r2, r0, r7, lsl #24
  68:	04040200 	streq	r0, [r4], #-512	; 0xfffffe00
  6c:	0000014a 	andeq	r0, r0, sl, asr #2
  70:	16040802 	strne	r0, [r4], -r2, lsl #16
  74:	04000001 	streq	r0, [r0], #-1
  78:	00000033 	andeq	r0, r0, r3, lsr r0
  7c:	00000087 	andeq	r0, r0, r7, lsl #1
  80:	00008705 	andeq	r8, r0, r5, lsl #14
  84:	02006300 	andeq	r6, r0, #0, 6
  88:	015a0704 	cmpeq	sl, r4, lsl #14
  8c:	1d060000 	stcne	0, cr0, [r6, #-0]
  90:	01000001 	tsteq	r0, r1
  94:	00770703 	rsbseq	r0, r7, r3, lsl #14
  98:	03050000 	movweq	r0, #20480	; 0x5000
  9c:	00000000 	andeq	r0, r0, r0
  a0:	00010807 	andeq	r0, r1, r7, lsl #16
  a4:	06050100 	streq	r0, [r5], -r0, lsl #2
  a8:	00000000 	andeq	r0, r0, r0
  ac:	0000001c 	andeq	r0, r0, ip, lsl r0
  b0:	Address 0x000000b0 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	0b0b0024 	bleq	2c00ac <main+0x2c00ac>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	16030000 	strne	r0, [r3], -r0
  20:	3a0e0300 	bcc	380c28 <main+0x380c28>
  24:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  28:	0013490b 	andseq	r4, r3, fp, lsl #18
  2c:	01010400 	tsteq	r1, r0, lsl #8
  30:	13011349 	movwne	r1, #4937	; 0x1349
  34:	21050000 	mrscs	r0, (UNDEF: 5)
  38:	2f134900 	svccs	0x00134900
  3c:	0600000b 	streq	r0, [r0], -fp
  40:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  44:	0b3b0b3a 	bleq	ec2d34 <main+0xec2d34>
  48:	13490b39 	movtne	r0, #39737	; 0x9b39
  4c:	1802193f 	stmdane	r2, {r0, r1, r2, r3, r4, r5, r8, fp, ip}
  50:	2e070000 	cdpcs	0, 0, cr0, cr7, cr0, {0}
  54:	03193f00 	tsteq	r9, #0, 30
  58:	3b0b3a0e 	blcc	2ce898 <main+0x2ce898>
  5c:	270b390b 	strcs	r3, [fp, -fp, lsl #18]
  60:	12011119 	andne	r1, r1, #1073741830	; 0x40000006
  64:	96184006 	ldrls	r4, [r8], -r6
  68:	00001942 	andeq	r1, r0, r2, asr #18
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000001c 	andeq	r0, r0, ip, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000004b 	andeq	r0, r0, fp, asr #32
   4:	00300003 	eorseq	r0, r0, r3
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	616c5000 	cmnvs	ip, r0
  28:	726f6674 	rsbvc	r6, pc, #116, 12	; 0x7400000
  2c:	79545f6d 	ldmdbvc	r4, {r0, r2, r3, r5, r6, r8, r9, sl, fp, ip, lr}^
  30:	2e736570 	mrccs	5, 3, r6, cr3, cr0, {3}
  34:	00000068 	andeq	r0, r0, r8, rrx
  38:	10050000 	andne	r0, r5, r0
  3c:	00020500 	andeq	r0, r2, r0, lsl #10
  40:	16000000 	strne	r0, [r0], -r0
  44:	054b0205 	strbeq	r0, [fp, #-517]	; 0xfffffdfb
  48:	06024b01 	streq	r4, [r2], -r1, lsl #22
  4c:	Address 0x0000004c is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
   4:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
   8:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
   c:	70610074 	rsbvc	r0, r1, r4, ror r0
  10:	00632e70 	rsbeq	r2, r3, r0, ror lr
  14:	746e6975 	strbtvc	r6, [lr], #-2421	; 0xfffff68b
  18:	6f6c0038 	svcvs	0x006c0038
  1c:	7520676e 	strvc	r6, [r0, #-1902]!	; 0xfffff892
  20:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  24:	2064656e 	rsbcs	r6, r4, lr, ror #10
  28:	00746e69 	rsbseq	r6, r4, r9, ror #28
  2c:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
  30:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
  34:	6e752067 	cdpvs	0, 7, cr2, cr5, cr7, {3}
  38:	6e676973 			; <UNDEFINED> instruction: 0x6e676973
  3c:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
  40:	4500746e 	strmi	r7, [r0, #-1134]	; 0xfffffb92
  44:	6d455c3a 	stclvs	12, cr5, [r5, #-232]	; 0xffffff18
  48:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  4c:	525c6465 	subspl	r6, ip, #1694498816	; 0x65000000
  50:	736f7065 	cmnvc	pc, #101	; 0x65
  54:	73614d5c 	cmnvc	r1, #92, 26	; 0x1700
  58:	69726574 	ldmdbvs	r2!, {r2, r4, r5, r6, r8, sl, sp, lr}^
  5c:	455f676e 	ldrbmi	r6, [pc, #-1902]	; fffff8f6 <main+0xfffff8f6>
  60:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  64:	5f646564 	svcpl	0x00646564
  68:	74737953 	ldrbtvc	r7, [r3], #-2387	; 0xfffff6ad
  6c:	5f736d65 	svcpl	0x00736d65
  70:	68746977 	ldmdavs	r4!, {r0, r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  74:	532e4b5f 			; <UNDEFINED> instruction: 0x532e4b5f
  78:	696e555c 	stmdbvs	lr!, {r2, r3, r4, r6, r8, sl, ip, lr}^
  7c:	455f3374 	ldrbmi	r3, [pc, #-884]	; fffffd10 <main+0xfffffd10>
  80:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  84:	5f646564 	svcpl	0x00646564
  88:	654c5c43 	strbvs	r5, [ip, #-3139]	; 0xfffff3bd
  8c:	6e6f7373 	mcrvs	3, 3, r7, cr15, cr3, {3}
  90:	6d455f32 	stclvs	15, cr5, [r5, #-200]	; 0xffffff38
  94:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  98:	435f6465 	cmpmi	pc, #1694498816	; 0x65000000
  9c:	554e4700 	strbpl	r4, [lr, #-1792]	; 0xfffff900
  a0:	37314320 	ldrcc	r4, [r1, -r0, lsr #6]!
  a4:	2e303120 	rsfcssp	f3, f0, f0
  a8:	20312e33 	eorscs	r2, r1, r3, lsr lr
  ac:	31323032 	teqcc	r2, r2, lsr r0
  b0:	34323830 	ldrtcc	r3, [r2], #-2096	; 0xfffff7d0
  b4:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  b8:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  bc:	2d202965 			; <UNDEFINED> instruction: 0x2d202965
  c0:	7570636d 	ldrbvc	r6, [r0, #-877]!	; 0xfffffc93
  c4:	6d72613d 	ldfvse	f6, [r2, #-244]!	; 0xffffff0c
  c8:	65363239 	ldrvs	r3, [r6, #-569]!	; 0xfffffdc7
  cc:	20732d6a 	rsbscs	r2, r3, sl, ror #26
  d0:	6c666d2d 	stclvs	13, cr6, [r6], #-180	; 0xffffff4c
  d4:	2d74616f 	ldfcse	f6, [r4, #-444]!	; 0xfffffe44
  d8:	3d696261 	sfmcc	f6, 2, [r9, #-388]!	; 0xfffffe7c
  dc:	74666f73 	strbtvc	r6, [r6], #-3955	; 0xfffff08d
  e0:	616d2d20 	cmnvs	sp, r0, lsr #26
  e4:	2d206d72 	stccs	13, cr6, [r0, #-456]!	; 0xfffffe38
  e8:	6372616d 	cmnvs	r2, #1073741851	; 0x4000001b
  ec:	72613d68 	rsbvc	r3, r1, #104, 26	; 0x1a00
  f0:	7435766d 	ldrtvc	r7, [r5], #-1645	; 0xfffff993
  f4:	2d206a65 	vstmdbcs	r0!, {s12-s112}
  f8:	6e750067 	cdpvs	0, 7, cr0, cr5, cr7, {3}
  fc:	6e676973 			; <UNDEFINED> instruction: 0x6e676973
 100:	63206465 			; <UNDEFINED> instruction: 0x63206465
 104:	00726168 	rsbseq	r6, r2, r8, ror #2
 108:	6e69616d 	powvsez	f6, f1, #5.0
 10c:	6e6f6c00 	cdpvs	12, 6, cr6, cr15, cr0, {0}
 110:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
 114:	6f640074 	svcvs	0x00640074
 118:	656c6275 	strbvs	r6, [ip, #-629]!	; 0xfffffd8b
 11c:	72747300 	rsbsvc	r7, r4, #0, 6
 120:	5f676e69 	svcpl	0x00676e69
 124:	66667562 	strbtvs	r7, [r6], -r2, ror #10
 128:	73007265 	movwvc	r7, #613	; 0x265
 12c:	74726f68 	ldrbtvc	r6, [r2], #-3944	; 0xfffff098
 130:	736e7520 	cmnvc	lr, #32, 10	; 0x8000000
 134:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0xfffff897
 138:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
 13c:	69730074 	ldmdbvs	r3!, {r2, r4, r5, r6}^
 140:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
 144:	61686320 	cmnvs	r8, r0, lsr #6
 148:	6c660072 	stclvs	0, cr0, [r6], #-456	; 0xfffffe38
 14c:	0074616f 	rsbseq	r6, r4, pc, ror #2
 150:	726f6873 	rsbvc	r6, pc, #7536640	; 0x730000
 154:	6e692074 	mcrvs	0, 3, r2, cr9, cr4, {3}
 158:	6e750074 	mrcvs	0, 3, r0, cr5, cr4, {3}
 15c:	6e676973 			; <UNDEFINED> instruction: 0x6e676973
 160:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
 164:	Address 0x00000164 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	4120554e 			; <UNDEFINED> instruction: 0x4120554e
   c:	45206d72 	strmi	r6, [r0, #-3442]!	; 0xfffff28e
  10:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  14:	20646564 	rsbcs	r6, r4, r4, ror #10
  18:	6c6f6f54 	stclvs	15, cr6, [pc], #-336	; fffffed0 <main+0xfffffed0>
  1c:	69616863 	stmdbvs	r1!, {r0, r1, r5, r6, fp, sp, lr}^
  20:	3031206e 	eorscc	r2, r1, lr, rrx
  24:	322d332e 	eorcc	r3, sp, #-1207959552	; 0xb8000000
  28:	2e313230 	mrccs	2, 1, r3, cr1, cr0, {1}
  2c:	20293031 	eorcs	r3, r9, r1, lsr r0
  30:	332e3031 			; <UNDEFINED> instruction: 0x332e3031
  34:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  38:	30313230 	eorscc	r3, r1, r0, lsr r2
  3c:	20343238 	eorscs	r3, r4, r8, lsr r2
  40:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  44:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  48:	Address 0x00000048 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000001c 	andeq	r0, r0, ip, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002b41 	andeq	r2, r0, r1, asr #22
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000021 	andeq	r0, r0, r1, lsr #32
  10:	45543505 	ldrbmi	r3, [r4, #-1285]	; 0xfffffafb
  14:	0506004a 	streq	r0, [r6, #-74]	; 0xffffffb6
  18:	01090108 	tsteq	r9, r8, lsl #2
  1c:	01140412 	tsteq	r4, r2, lsl r4
  20:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
