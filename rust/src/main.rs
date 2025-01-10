use colored::Colorize;
use std::{
    fs::File,
    io::{BufRead, BufReader, Read},
};

/// Print help messages when program
/// would fail due to bad input
fn print_help() {
    let args: Vec<String> = std::env::args().collect();

    println!("usage: {} <target> <file/stream>", args[0]);
}

/// Read input either from a file
/// if a filename is provided, or stdin if not
fn read_input(filename: &Option<String>) -> BufReader<impl Read> {
    let reader: Box<dyn Read> = match filename {
        Some(filename) => match File::open(filename) {
            Ok(file) => Box::new(file),
            Err(_) => {
                print_help();
                std::process::exit(1);
            }
        },
        None => Box::new(std::io::stdin().lock()),
    };

    BufReader::new(reader)
}

/// Grep arguments
#[derive(Debug)]
struct Args {
    pattern: String,
    file_name_or_stream: Option<String>,
}

impl Args {
    /// Wrapper for std::env::args
    fn read_from_stdenv() -> Vec<String> {
        let args: Vec<String> = std::env::args().collect();
        args
    }

    /// Parse std::env::args to Args struct
    fn parse(args: Vec<String>) -> Args {
        if args.len() < 2 || args.len() > 3 {
            print_help();
        }

        let pattern = match args.get(1) {
            Some(v) => v.clone(),
            None => {
                print_help();
                std::process::exit(1);
            }
        };

        // Catch for `grep --help`
        if [
            String::from("help"),
            String::from("--help"),
            String::from("-h"),
        ]
        .contains(&pattern)
            && args.len() == 2
        {
            print_help();
            std::process::exit(0);
        }

        let file_name_or_stream = args.get(2).cloned();

        Args {
            pattern,
            file_name_or_stream,
        }
    }
}

/// amogus
fn main() -> Result<(), ()> {
    let args = Args::parse(Args::read_from_stdenv());

    let reader = read_input(&args.file_name_or_stream);

    for mut line in reader.lines().map_while(Result::ok) {
        if !line.contains(&args.pattern) {
            continue;
        }

        line = line.replace(&args.pattern, &args.pattern.bright_red().to_string());
        println!("{}", line);
    }

    Ok(())
}
