--
-- PostgreSQL database dump
--

-- Dumped from database version 12.8 (Ubuntu 12.8-1.pgdg20.04+1)
-- Dumped by pg_dump version 12.8 (Ubuntu 12.8-1.pgdg20.04+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: data; Type: TABLE; Schema: public; Owner: cricciardi
--

CREATE TABLE public.data (
    id integer NOT NULL,
    serviceid integer NOT NULL,
    userid integer NOT NULL,
    data character varying(255) NOT NULL
);


ALTER TABLE public.data OWNER TO cricciardi;

--
-- Name: data_id_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.data_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.data_id_seq OWNER TO cricciardi;

--
-- Name: data_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.data_id_seq OWNED BY public.data.id;


--
-- Name: data_serviceid_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.data_serviceid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.data_serviceid_seq OWNER TO cricciardi;

--
-- Name: data_serviceid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.data_serviceid_seq OWNED BY public.data.serviceid;


--
-- Name: data_userid_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.data_userid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.data_userid_seq OWNER TO cricciardi;

--
-- Name: data_userid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.data_userid_seq OWNED BY public.data.userid;


--
-- Name: service; Type: TABLE; Schema: public; Owner: cricciardi
--

CREATE TABLE public.service (
    id integer NOT NULL,
    service character varying(255) NOT NULL,
    userid integer NOT NULL
);


ALTER TABLE public.service OWNER TO cricciardi;

--
-- Name: service_id_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.service_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.service_id_seq OWNER TO cricciardi;

--
-- Name: service_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.service_id_seq OWNED BY public.service.id;


--
-- Name: service_userid_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.service_userid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.service_userid_seq OWNER TO cricciardi;

--
-- Name: service_userid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.service_userid_seq OWNED BY public.service.userid;


--
-- Name: users; Type: TABLE; Schema: public; Owner: cricciardi
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(200) NOT NULL,
    phone_number character varying(200) NOT NULL,
    email character varying(200) NOT NULL,
    password character varying(200) NOT NULL
);


ALTER TABLE public.users OWNER TO cricciardi;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO cricciardi;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: data id; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.data ALTER COLUMN id SET DEFAULT nextval('public.data_id_seq'::regclass);


--
-- Name: data serviceid; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.data ALTER COLUMN serviceid SET DEFAULT nextval('public.data_serviceid_seq'::regclass);


--
-- Name: data userid; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.data ALTER COLUMN userid SET DEFAULT nextval('public.data_userid_seq'::regclass);


--
-- Name: service id; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.service ALTER COLUMN id SET DEFAULT nextval('public.service_id_seq'::regclass);


--
-- Name: service userid; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.service ALTER COLUMN userid SET DEFAULT nextval('public.service_userid_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: data; Type: TABLE DATA; Schema: public; Owner: cricciardi
--

COPY public.data (id, serviceid, userid, data) FROM stdin;
\.


--
-- Data for Name: service; Type: TABLE DATA; Schema: public; Owner: cricciardi
--

COPY public.service (id, service, userid) FROM stdin;
1	1-4,3-1	1
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: cricciardi
--

COPY public.users (id, name, phone_number, email, password) FROM stdin;
1	Charles	+33767063130	charles.ricciardi@epitech.eu	password
2	Manu	0767063130	manu@macron.com	$2b$10$ZpSrvo56IOm9F2koGhCKNeThJNakJDCuAHIhnHyVEsJbiZ0C4N7bG
3	fzef	feaf	fea	$2b$10$zdcFlKwjZJOZVnSClUXzN.iCWxt37BoIe8vAOEihle3aES6zhA2p.
4	charles	paegoizg	paugoag	$2b$10$j77Ckb6WoNhO7eSY052oT.Lf5M.BzLEkPBHncctrlBTwBygrRr39m
5	gareg	gaezg	gazeg	$1
6	azret	zteezt	ertztez	$1
7	waka	fe	fe	$2b$10$u/6yhhbDkuiI6hK8qgJg9ORyuo67PNDjcGs77VGik9vQ7I8mXPJwm
8	eazr	raez	raez	$2b$10$UiRSPCGmnNIcHt01nb47QOEq8W.n46wgX8yO54P4kxu3u24rleb8G
9	bfbfb	ttt	azerzzzz	$2b$10$7lc5pIG1c/VOiqYsIpnZZedWUs3ugWcV05E5/.8xM/eIFmLu/z/dm
\.


--
-- Name: data_id_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.data_id_seq', 1, false);


--
-- Name: data_serviceid_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.data_serviceid_seq', 1, false);


--
-- Name: data_userid_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.data_userid_seq', 1, false);


--
-- Name: service_id_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.service_id_seq', 1, true);


--
-- Name: service_userid_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.service_userid_seq', 1, false);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: cricciardi
--

SELECT pg_catalog.setval('public.users_id_seq', 9, true);


--
-- Name: data data_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.data
    ADD CONSTRAINT data_pkey PRIMARY KEY (id);


--
-- Name: service service_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.service
    ADD CONSTRAINT service_pkey PRIMARY KEY (id);


--
-- Name: users users_email_key; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_key UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

