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




--
-- Name: data_userid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.data_userid_seq OWNED BY public.data.userid;


--
-- Name: services; Type: TABLE; Schema: public; Owner: cricciardi
--
CREATE TABLE public.discord (
  discord_id VARCHAR PRIMARY KEY,
  created_at TIMESTAMP DEFAULT NOW()
);

CREATE TABLE public.services (
    id integer NOT NULL,
    name character varying(255) NOT NULL,
    action_service character varying(255) NOT NULL,
    action character varying(255) NOT NULL,
    reaction_service character varying(255) NOT NULL,
    reaction character varying(255) NOT NULL,
    user_id integer NOT NULL
);




--
-- Name: services_id_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.services_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;




--
-- Name: services_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: cricciardi
--

ALTER SEQUENCE public.services_id_seq OWNED BY public.services.id;


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


CREATE TABLE public.states (
    id SERIAL PRIMARY KEY,
    service_id VARCHAR(255) NOT NULL,
    state VARCHAR NOT NULL
);

ALTER TABLE public.states ADD CONSTRAINT unique_service_id UNIQUE (service_id);
--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: cricciardi
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


CREATE TABLE public.oauth2 (
    id SERIAL PRIMARY KEY,
    user_id VARCHAR(255) NOT NULL,
    token VARCHAR(255) NOT NULL,
    service_id VARCHAR(255) NOT NULL,
    token_type VARCHAR(255) NOT NULL,
    api_uid VARCHAR(255) NOT NULL
);

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
-- Name: services id; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.services ALTER COLUMN id SET DEFAULT nextval('public.services_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Name: data data_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.data
    ADD CONSTRAINT data_pkey PRIMARY KEY (id);


--
-- Name: services services_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.services
    ADD CONSTRAINT services_pkey PRIMARY KEY (id);


--
-- Name: users users_email_key; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: cricciardi
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

